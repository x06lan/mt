library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.ALL;

entity lab8 is
port(
	clk : in std_logic;
	HEX1 : out std_logic_vector(0 to 6);--MSB
	HEX0 : out std_logic_vector(0 to 6);--LSB
	
	red1 : out std_logic;
	red2 : out std_logic;
	yel1 : out std_logic;
	yel2 : out std_logic;
	gre1 : out std_logic;
	gre2 : out std_logic);
end lab8;

architecture behavioral of lab8 is
begin
	process(clk) is
	variable s1 : integer :=0; 
	variable s2 : integer :=0;
	variable count : integer :=0;
	variable redCount : integer;
	variable msbans : integer;
	variable lsbans : integer;
	begin
		if (clk'event and clk='1') then
			s1:=s1+1;
			if (count = 0) then
				red1<='1';
				red2<='0';
				yel1<='0';
				yel2<='0';
				gre1<='0';
				gre2<='1';
				redCount:=20;
			end if;
			if(s1>20000) then
				s2:=s2+1;
				if(s2>2500) then
					count:=count+1;
					redCount:=redCount-1;
					if(count mod 4 = 0) then
						if(count/4 = 4) then
							red1<='1';
							red2<='0';
							yel1<='0';
							yel2<='1';
							gre1<='0';
							gre2<='0';
						elsif(count/4 = 5) then
							red1<='0';
							red2<='1';
							yel1<='0';
							yel2<='0';
							gre1<='1';
							gre2<='0';
							redCount:=20;
						elsif(count/4 = 9) then
							red1<='0';
							red2<='1';
							yel1<='1';
							yel2<='0';
							gre1<='0';
							gre2<='0';
						elsif(count/4 = 10) then
							redCount:=20;
							count:=0;
						end if;
					end if;
						msbAns := redCount / 10;
						lsbAns := redCount Mod 10;
						if (msbAns = 2) then HEX1 <= "0010010";
						elsif (msbAns = 1) then HEX1 <= "1001111";
						elsif (msbAns = 0) then HEX1 <= "0000001";
						else HEX1 <= "1111111";
						end if;

					
						if (lsbAns = 9) then HEX0 <= "0001100";
						elsif (lsbAns = 8) then HEX0 <= "0000000";
						elsif (lsbAns = 7) then HEX0 <= "0001111";
						elsif (lsbAns = 6) then HEX0 <= "1100000";
						elsif (lsbAns = 5) then HEX0 <= "0100100";
						elsif (lsbAns = 4) then HEX0 <= "1001100";
						elsif (lsbAns = 3) then HEX0 <= "0000110";
						elsif (lsbAns = 2) then HEX0 <= "0010010";
						elsif (lsbAns = 1) then HEX0 <= "1001111";
						elsif (lsbAns = 0) then HEX0 <= "0000001";
						else HEX0 <= "1111111";
						end if;

					s2:=0;
				end if;
				s1:=0;
				
			end if;

		end if;
	end process;
end behavioral;