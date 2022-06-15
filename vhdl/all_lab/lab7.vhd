--**********************************************************************************
-- Lab Title : 8x8 Dot-matrix LEDs Display Advanced
-- School    : Daan_High_school()
-- Author    :
-- CPLD      : Altera MAX II EPM1270T44C5
-- Data      : 109-06-04
--**********************************************************************************


library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;


entity lab7 is
generic(fmax:integer:=5E7);
port(
		clk			:in std_logic;
		rst			:in std_logic;
		dip_sw		:in std_logic_vector(1 downto 0);

		matrix_col	:out std_logic_vector(7 downto 0);
		scan_row	:out std_logic_vector(7 downto 0)
	);
end lab7;


architecture beh of lab7 is



	signal cnt1		:std_logic_vector(25 downto 0);
	signal cnt2		:std_logic_vector(25 downto 0);
	signal cnt3		:std_logic_vector(25 downto 0);
	signal scan_cnt	:integer range 0 to 7;
	signal clk_1p	:std_logic;
	signal clk_5p	:std_logic;
	signal clk_1kp	:std_logic;
	signal cnt_p	:std_logic;


	signal bcd1 : integer range 0 to 9;
	signal bcd0 : integer range 0 to 9;


	type encode	 is array(0 to 7) of std_logic_vector(3 downto 0);

	type ROM	 is array(0 to 9) of encode;

	constant char_ROM:ROM:=	(("1001",--0
							  "0110",
							  "0110",
							  "0110",
							  "0110",
							  "0110",
							  "1001",
							  "1111"),

							 ("1101",--1
							  "1001",
							  "1101",
							  "1101",
							  "1101",
							  "1101",
							  "1000",
							  "1111"),

							 ("0001",--2
							  "1110",
							  "1110",
							  "1001",
							  "0111",
							  "0111",
							  "0000",
							  "1111"),

							 ("0001",--3
							  "1110",
							  "1110",
							  "0000",
							  "1110",
							  "1110",
							  "0001",
							  "1111"),

							 ("0110",--4
							  "0110",
							  "0110",
							  "0000",
							  "1110",
							  "1110",
							  "1110",
							  "1111"),

							 ("0000",--5
							  "0111",
							  "0111",
							  "0001",
							  "1110",
							  "1110",
							  "0000",
							  "1111"),

							 ("0000",--6
							  "0111",
							  "0111",
							  "0000",
							  "0110",
							  "0110",
							  "0000",
							  "1111"),

							 ("0000",--7
							  "1110",
							  "1110",
							  "1101",
							  "1101",
							  "1011",
							  "1011",
							  "1111"),

							 ("1001",--8
							  "0110",
							  "0110",
							  "0000",
							  "0110",
							  "0110",
							  "1001",
							  "1111"),

							 ("0000",--9
							  "0110",
							  "0110",
							  "0000",
							  "1110",
							  "1110",
							  "1000",
							  "1111")
						);


	type RAM is array (0 to 7) of std_logic_vector(7 downto 0);
	signal RAM_8x8:RAM;

begin


	cnt_p <= clk_1p when (dip_sw(0)='0')else clk_5p;


	process(clk,rst)
	begin
		if(rst = '0')then
			cnt1	<=(others=>'0');
			cnt2	<=(others=>'0');
			cnt3	<=(others=>'0');
			scan_cnt<=0;
		elsif(clk'event and clk = '1')then


			if(cnt1 <fmax/1-1)then
				cnt1	<=cnt1 + 1;
				clk_1p	<='0';
			else
				cnt1	<=(others=>'0');
				clk_1p	<='1';
			end if;


			if(cnt2 < fmax/5-1)then
				cnt2	<=cnt2+1;
				clk_5p	<='0';
			else
				cnt2	<=(others=>'0');
				clk_5p	<='1';
			end if;


			if(cnt3<fmax/1E3-1)then
				cnt3	<=cnt3+1;
				clk_1kp	<='0';
			else
				cnt3	<=(others=>'0');
				clk_1kp<='1';
			end if;


			if(clk_1kp='1')then
				if(scan_cnt<7)then
					scan_cnt<=scan_cnt+1;
				else
					scan_cnt<=0;
				end if;
			end if;
		end if;
	end process;


	process(clk)
	begin
		if(rst='0')then
			bcd0<=0;
			bcd1<=0;
		elsif(clk'event and clk = '1')then


			if(dip_sw(1) ='0')then
				if(cnt_p ='1')then
					if(bcd0 < 9)then
						bcd0 <= bcd0 + 1;
					elsif(bcd1 < 9)then
						bcd0 <= 0;
						bcd1 <= bcd1 + 1;
					else
						bcd0 <= 0;
						bcd1 <= 0;
					end if;
				end if;
			else
				if(cnt_p = '1')then
					if(bcd0 > 0)then
						bcd0 <= bcd0 - 1;
					elsif(bcd1 > 0)then
						bcd0 <= 9;
						bcd1 <= bcd1 - 1;
					else
						bcd0 <= 9;
						bcd1 <= 9;
					end if;
				end if;
			end if;


			for i in 0 to 7 loop
				RAM_8x8(i) <= char_ROM(bcd1)(i) & char_ROM(bcd0)(i);
			end loop;
		end if;
	end process;



	scan_row <= "11111110" when(scan_cnt = 0) else
				"11111101" when(scan_cnt = 1) else
				"11111011" when(scan_cnt = 2) else
				"11110111" when(scan_cnt = 3) else
				"11101111" when(scan_cnt = 4) else
				"11011111" when(scan_cnt = 5) else
				"10111111" when(scan_cnt = 6) else
				"01111111";
	matrix_col <= RAM_8x8(0) when(scan_cnt = 0) else
				RAM_8x8(1) when(scan_cnt = 1) else
				RAM_8x8(2) when(scan_cnt = 2) else
				RAM_8x8(3) when(scan_cnt = 3) else
				RAM_8x8(4) when(scan_cnt = 4) else
				RAM_8x8(5) when(scan_cnt = 5) else
				RAM_8x8(6) when(scan_cnt = 6) else
				RAM_8x8(7);


end beh;
