--*****************************************************************************
-- Title	: 10 SWs to BCD to 7-Segment Display (comm-Anode) with DIPSW scan-code
-- School	: Daan_High_School()
-- Author	:
-- CPLD		: Altera MAX II EPM1270T44C5
-- Data		: 109-03-26
--*****************************************************************************
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity lab1 is
port(
  sw_in     :in std_logic_vector(9 downto 0);
  scansw_in :in std_logic_vector(2 downto 0);
  scan_out  :out std_logic_vector(7 downto 0);
  seg_out   :out std_logic_vector(7 downto 0)
)
end lab1;

architecture beh of lab1 is

  signal bcd:std_logic_vector(3 downto 0);

begin
  scan_out <= "11111110" when(scansw_in="000")else
              "11111101" when(scansw_in="001")else
              "11111011" when(scansw_in="010")else
              "11110111" when(scansw_in="011")else
              "11101111" when(scansw_in="100")else
              "11011111" when(scansw_in="101")else
              "10111111" when(scansw_in="110")else
              "01111111" when(scansw_in="111")else
              "11111111";

  bcd <= "1001" when(sw_in(9)='1')else
         "1000" when(sw_in(8)='1')else
         "0111" when(sw_in(7)='1')else
         "0110" when(sw_in(6)='1')else
         "0101" when(sw_in(5)='1')else
         "0100" when(sw_in(4)='1')else
         "0011" when(sw_in(3)='1')else
         "0010" when(sw_in(2)='1')else
         "0001" when(sw_in(1)='1')else
         "0000";

  scan_out <= "10010000" when(bcd="1001")else
              "10000000" when(bcd="1000")else
              "11111000" when(bcd="0111")else
              "10000010" when(bcd="0110")else
              "10010010" when(bcd="0101")else
              "10011001" when(bcd="0100")else
              "10110000" when(bcd="0011")else
              "10100100" when(bcd="0010")else
              "11111001" when(bcd="0001")else
              "11000000";

end beh;
