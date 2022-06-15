--**********************************************************************************
-- Lab Title : 8x8 Dot-matrix LEDs Display
-- School    : Daan_High_school()
-- Author    :
-- CPLD      : Altera MAX II EPM1270T44C5
-- Data      : 109-05-21
--**********************************************************************************


library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity lab6 is
generic(fmax : integer :=5E7);
port(
		clk		:in std_logic;
		clr		:in std_logic;
		tact_sw	:in std_logic_vector(2 downto 0);
		dip_sw	:in std_logic_vector(4 downto 0);

		matrix_out	:out std_logic_vector(7 downto 0);
		scan_row	:out std_logic_vector(7 downto 0)
	);
end lab6;

architecture beh of lab6 is
	signal cnt1		:std_logic_vector(25 downto 0);
	signal cnt2		:std_logic_vector(25 downto 0);
	signal cnt3		:integer range 0 to 7;
	signal number	:integer range 0 to 9;
	signal clk_1p	:std_logic;
	signal clk_1kp	:std_logic;
	signal temp		:integer range 0 to 15;

	type	encode is array (0 to 7) of std_logic_vector(7 downto 0);
	type	ROM is array (0 to 9) of encode;
	signal table : encode;

	constant char_ROM : ROM :=(("11000011", --0
								"10111101",
								"10111001",
								"10110101",
								"10101101",
								"10011101",
								"10111101",
								"11000011"),

							   ("11110111", --1
								"11100111",
								"11010111",
								"11110111",
								"11110111",
								"11110111",
								"11110111",
								"11000001"),

							   ("11000011", --2
								"10111101",
								"10111101",
								"11111011",
								"11110111",
								"11101111",
								"11011111",
								"10000001"),

							   ("11000111", --3
								"10111011",
								"11111011",
								"11000111",
								"11111011",
								"11111011",
								"11111011",
								"11000111"),

							   ("11100111", --4
								"11100111",
								"11010111",
								"11010111",
								"10110111",
								"10000011",
								"11110111",
								"11110111"),

							   ("10000011", --5
								"10111111",
								"10111111",
								"10000111",
								"11111011",
								"11111011",
								"10111011",
								"11000111"),

							   ("11100011", --6
								"11011111",
								"10111111",
								"10000111",
								"10111011",
								"10111011",
								"10111011",
								"11000111"),

							   ("10000011", --7
								"11111011",
								"11110111",
								"11110111",
								"11101111",
								"11101111",
								"11011111",
								"11011111"),

							   ("11000111", --8
								"10111011",
								"10111011",
								"11000111",
								"10111011",
								"10111011",
								"10111011",
								"11000111"),

							   ("11000011", --9
								"10111011",
								"10111011",
								"10111011",
								"11000011",
								"11111011",
								"11110111",
								"10001111")
							);

begin

	table	<= char_ROM(number);
	process(clk,clr)
	begin
		if(clr = '0')then
			cnt1 <=(others => '0');
		elsif(clk'event and clk = '1')then
			if(cnt1 < fmax / 1 - 1)then
				cnt1	<=cnt1 + 1;
				clk_1p	<= '0';
			else
				cnt1	<=(others => '0');
				clk_1p	<= '1';
			end if;
		end if;
	end process;

	process(clk,clr)
	begin
		if(clr = '0')then
			cnt2 <=(others => '0');
		elsif(clk'event and clk = '1')then
			if(cnt2 < fmax / 1E3 - 1)then
				cnt2	<= cnt2 + 1;
				clk_1kp	<= '0';
			else
				cnt2	<=(others => '0');
				clk_1kp	<= '1';
			end if;
		end if;
	end process;

	process(clk)
	begin
		if(clr = '0')then
			cnt3 	<= 0;
			number	<= 0;
		elsif(clk'event and clk = '1')then
			if(dip_sw(4) = '0')then
				if(clk_1p = '1')then
					if(number < 9)then
						number	<=number + 1;

					else
						number	<= 0;
					end if;
				end if;

			else
				temp	<=conv_integer(dip_sw(3 downto 0));
				if(temp < 10)then
					number <= temp;
				else
					number <= 0;
				end if;
			end if;

			if(clk_1kp = '1')then
				if(cnt3 < 7)then
					cnt3 <=cnt3 + 1;
				else
					cnt3 <= 0;
				end if;
			end if;
		end if;
	end process;

scan_row <= "11111111" when(clr ='0')else
			"11111110" when(cnt3 = 0) else
			"11111101" when(cnt3 = 1) else
			"11111011" when(cnt3 = 2) else
			"11110111" when(cnt3 = 3) else
			"11101111" when(cnt3 = 4) else
			"11011111" when(cnt3 = 5) else
			"10111111" when(cnt3 = 6) else
			"01111111";
matrix_out <= "11111111" when(clr = '0')else
				table(0) when(cnt3 = 0) else
				table(1) when(cnt3 = 1) else
				table(2) when(cnt3 = 2) else
				table(3) when(cnt3 = 3) else
				table(4) when(cnt3 = 4) else
				table(5) when(cnt3 = 5) else
				table(6) when(cnt3 = 6) else
				table(7);

end beh;
