library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity lab4 is
  port(
  clk : in std_logic;
  SW : in std_logic_vector(8 downto 0);
  seg7_out : out std_logic_vector(6 downto 0);
  seg7_com : out std_logic
  );
end lab4;
architecture structure of lab4 is
  shared variable timer : integer range 0 to 5E7-1 := 0;
  shared variable count : integer range 0 to 9 := 0;
begin
  process(clk)
  begin
    L1: for I in 8 downto 0 loop
        if (SW(I) = '1') then
            count := I;
            exit L1;
        else if (I = 0) then
            count  := 9;
            exit L1;
        end if;
        end if;
    end loop;
         case count is
         when 0 =>
         seg7_out <= "0000001"; --0
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
        seg7_out <= "1111111"; ---null
         when others =>
         seg7_out <= "1111111"; ---null
         end case;
  end process;
end structure;