--**********************************************************************************
-- Lab Title : Pili LED with 2 to 1 MUX (10Hz or 50Hz)
-- School    : Daan_High_school()
-- Author    :
-- CPLD      : Altera MAX II EPM1270T44C5
-- Data      : 109-04-30
--**********************************************************************************
--1. Libraries Declarations and Packages usage
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
--**********************************************************************************
--2. Entity Declarations

entity lab4 is
  generic (fmax: integer := 5E7);-- 50MHz
port(-- input pins
  clk : in std_logic;--Pin = 18
  dip_sw : in std_logic_vector(3 downto 0);--Pin = 10-16-20-21
  dip_sw_fn : in std_logic_vector(1 downto 0);--Pin = 10-16-20-21
  --output pins
  rgb_led : out std_logic_vector(2 downto 0);
  led_act : out std_logic_vector(7 downto 0)
	);
end lab4;
--**********************************************************************************
--3.Architectures (Body)
architecture BHVR of  lab4 is
  signal f_10p, f_5p : std_logic;
  signal f_p, flag : std_logic;
  signal scan : integer range 0 to 15;
  signal temp : std_logic_vector(7 downto 0);
begin
  --System Connections
  --1. 2 to 1 MUX


  f_p <= f_5p when (dip_sw(3) = '0') else
         f_10p;
  process(clk)
  variable cnt :std_logic_vector (25 downto 0);
  begin
    if (clk = '1')then
      cnt := cnt + 1;
      if (cnt < fmax / 10 -1) then
        f_10p <= '0';
      else
        f_10p <= '1';
        cnt := (others => '0');
      end if;
    end if;
  end process;

  process(clk)
  variable cnt : std_logic_vector(25 downto 0);
  begin
    if (clk = '1') then
      cnt := cnt + 1;
      if (cnt < fmax / 5 - 1) then
        f_5p <= '0';
      else
        f_5p <= '1';
        cnt := (others => '0');
      end if;
    end if;
  end process;
  process(clk)
  begin
    if clk = '1' then
      if (f_p = '1') then
        if (scan < 7 and flag = '0') then
          flag <= '0';
          scan <= scan +1;
        else
          flag <= '1';
          scan <= scan -1;
          if (scan = 0 and flag = '1') then
            flag <= '0';
            scan <= scan +1;
          end if;
        end if;
      end if;
    end if;
  end process;

  temp <="10000001" when ((scan = 0 or scan = 8) and dip_sw_fn = "00") else
         "01000010" when ((scan = 1 or scan = 9) and dip_sw_fn = "00") else
         "00100100" when ((scan = 2 or scan = 10) and dip_sw_fn = "00") else
         "00011000" when ((scan = 3 or scan = 11) and dip_sw_fn = "00") else
         "00100100" when ((scan = 4 or scan = 12) and dip_sw_fn = "00") else
         "01000010" when ((scan = 5 or scan = 13) and dip_sw_fn = "00") else
         "10000001" when ((scan = 6 or scan = 14) and dip_sw_fn = "00") else
         "00000000" when ((scan = 7 or scan = 15) and dip_sw_fn = "00") else

         "10000000" when ((scan = 0 or scan = 15) and dip_sw_fn = "01") else
         "11000000" when ((scan = 1 or scan = 14) and dip_sw_fn = "01") else
         "11100000" when ((scan = 2 or scan = 13) and dip_sw_fn = "01") else
         "11110000" when ((scan = 3 or scan = 12) and dip_sw_fn = "01") else
         "11111000" when ((scan = 4 or scan = 11) and dip_sw_fn = "01") else
         "11111100" when ((scan = 5 or scan = 10) and dip_sw_fn = "01") else
         "11111110" when ((scan = 6 or scan = 9) and dip_sw_fn = "01") else
         "11111111" when ((scan = 7 or scan = 8) and dip_sw_fn = "01") else

         "00000000" when (scan = 0 and dip_sw_fn = "11") else
         "11111111" when (scan = 1 and dip_sw_fn = "11") else
         "00000000" when (scan = 2 and dip_sw_fn = "11") else
         "11111111" when (scan = 3 and dip_sw_fn = "11") else
         "00000000" when (scan = 4 and dip_sw_fn = "11") else
         "11111111" when (scan = 5 and dip_sw_fn = "11") else
         "00000000" when (scan = 6 and dip_sw_fn = "11") else
         "11111111" when (scan = 7 and dip_sw_fn = "11");
  led_act <= not temp;

  rgb_led <= "011" when (dip_sw(2 downto 0) = "000") else
             "101" when (dip_sw(2 downto 0) = "001") else
             "110" when (dip_sw(2 downto 0) = "010") else
             "001" when (dip_sw(2 downto 0) = "011") else
             "010" when (dip_sw(2 downto 0) = "100") else
             "100" when (dip_sw(2 downto 0) = "101") else
             "000" when (dip_sw(2 downto 0) = "110") else
             "000";

end BHVR;
