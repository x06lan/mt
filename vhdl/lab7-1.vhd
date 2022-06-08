library ieee;
library IEEE;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity lab7 is
  port(
  clk : in std_logic;
  data: in std_logic;
  seg7_out : out std_logic_vector(0 to 6);
  seg7_out2 : out std_logic_vector(0 to 6);
  led: out std_logic_vector(0 to 5)
  );
end lab8;
architecture structure of lab8 is
  shared variable out1 : integer range 0 to 100 := 0;
  shared variable out2 : integer range 0 to 100 := 0;
  shared variable count: integer range 0 to 10000000000 := 0;
  shared variable sen: integer range 0 to 10000000000 := 0;
  shared variable cyc: integer range 0 to 100 := 0;
begin
  process(clk)
  begin
	  	if (rising_edge(clk))then
	  		count:=count+1;
			if(count mod 50000000= 0) then
				sen:=sen+1;
				if(sen mod 3=0)then
					cyc:=cyc+1;
				end if;
			end if;
		end if;
		if(cyc=10)then
			count:=0;
			cyc:=0;
		end if;
		if(cyc<4)then 
			led(0):='1';
			led(5):='1';
		else
			led(0):='0';
			led(5):='0';
		end if;
		if(cyc=4)then 
			led(0):='1';
			led(4):='1';
		end if;
		if(cyc>4)then 
			led(2):='1';
			led(3):='1';
		else
			led(2):='0';
			led(3):='0';
		end if;
		if(cyc=9) then
			led(1)='1';
			led(3)='1';
		end if;
		seg7_out=(15-sen)/10;
		seg7_out=(15-sen) mod 10;
		

    case out1 is
         when 0 =>
         seg7_out <= "0000001"; ---0
         when 1 =>
         seg7_out <= "1001111"; ---1
         when 2 =>
         seg7_out <= "0010010"; ---2
         when 3 =>
         seg7_out <= "0000110"; ---3
         when 4 =>
         seg7_out <= "1001100"; ---4
         when 5 =>
         seg7_out <= "0100100"; ---5
         when 6 =>
         seg7_out <= "0100000"; ---6
         when 7 =>
         seg7_out <= "0001111"; ---7
         when 8 =>
         seg7_out <= "0000000"; ---8
         when 9 =>
         seg7_out <= "0001100"; ---9
         when others =>
         seg7_out <= "1111111"; ---null
         end case;

	case out2 is
         when 0 =>
         seg7_out2 <= "0000001"; ---0
         when 1 =>
         seg7_out2 <= "1001111"; ---1
         when 2 =>
         seg7_out2 <= "0010010"; ---2
         when 3 =>
         seg7_out2 <= "0000110"; ---3
         when 4 =>
         seg7_out2 <= "1001100"; ---4
         when 5 =>
         seg7_out2 <= "0100100"; ---5
         when 6 =>
         seg7_out2 <= "0100000"; ---6
         when 7 =>
         seg7_out2 <= "0001111"; ---7
         when 8 =>
         seg7_out2 <= "0000000"; ---8
         when 9 =>
         seg7_out2 <= "0001100"; ---9
         when others =>
         seg7_out2 <= "1111111"; ---null
         end case;
  end process;
end structure;
