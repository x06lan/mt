library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.ALL;

entity lab8 is
port(
	clk : in std_logic;
--	rst : in std_logic;
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
			end if;
			if(s1>20000)	then
				s2:=s2+1;
				if(s2>2500) then
					count:=count+1;
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
							elsif(count/4 = 9) then
								red1<='0';
								red2<='1';
								yel1<='1';
								yel2<='0';
								gre1<='0';
								gre2<='0';
							elsif(count/4 = 10) then
								count:=0;
							end if;
						end if;
					s2:=0;
				end if;
				s1:=0;
			end if;
		end if;
	end process;
end behavioral;
--				red1:='1';
--				red2:='0';
--				yel1:='0';
--				yel2:='0';
--				gre1:='0';
--				gre2:='1';