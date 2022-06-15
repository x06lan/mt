--*************************************************************************************************************************
-- Title	: Tact SW and 4 BCD Data to 8 Digits 7-Segment Display (comm-Anode)
-- School	: Daan_High_School()
-- Author	:
-- CPLD		: Altera MAX II EPM1270T44C5
-- Data		: 109-04-16
--*************************************************************************************************************************
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity jaja is
generic(fmax : integer := 5E7); -- CPLD provides 50MHz

port(
  clk  : in std_logic; --50MHz on CPLD
  sw  : in std_logic; --Low active 0-> stdID, 1->Date
  scan : out std_logic_vector(7 downto 0); --Low active
  sw_gnd  : out std_logic; --Common-Anode -> connect to GND
  seg_out : out std_logic_vector(7 downto 0)
 );
end jaja;

architecture beh of jaja is
 signal rst     : std_logic;
 signal fq_div  : std_logic;
 signal q0,q1   : std_logic;
 signal q2,q3   : std_logic;
 signal diff_np : std_logic; --distinguish pulse
 signal diff_pp : std_logic; --distinguish pulse
 signal scan_cnt : std_logic_vector(2 downto 0);
 signal bcd   : integer range 0 to 10;
 signal bcd7_t  : integer range 0 to 10;
 signal bcd6_t  : integer range 0 to 10;
 signal bcd5_t  : integer range 0 to 10;
 signal bcd4_t  : integer range 0 to 10;
 signal bcd3_t  : integer range 0 to 10;
 signal bcd2_t  : integer range 0 to 10;
 signal bcd1_t  : integer range 0 to 10;
 signal bcd0_t  : integer range 0 to 10;
 signal dash  : integer range 0 to 10 := 10;
begin
 sw_gnd <= '0';

 process(clk)
  variable cnt0 : std_logic_vector(15 downto 0);
  variable cnt1 : std_logic_vector(15 downto 0);
 begin
  if(clk'event and clk = '1') then --positive edge
   if(cnt0 < fmax/10E3-1) then
    cnt0 := cnt0+1;
    rst<= '0';
   else
    rst<= '1';
   end if;
   cnt1 := cnt1+1;
   if(cnt1 < fmax/10E3-1) then
    fq_div <= '0';
   else
    fq_div <= '1';
    cnt1 := (others => '0');
   end if;
  end if;
 end process;

 process(clk, rst)
 begin
 if(rst = '0') then
  q1<='0';
  q0<='0';
 elsif(clk'event and clk = '1')then
  if(fq_div = '1' and clk = '1')then
   q1<= q0;
   q0<= sw;
  end if;
 end if;
 end process;

 process(clk, rst)
 begin
  if(rst = '0') then
   q3<='0';
   q2<='0';
  elsif(clk'event and clk = '1')then
   q3<= q2;
   q2<= q1;
  end if;
 end process;

 diff_pp <= (not q3) and q2; --global signal (select the circuit)
 diff_np <= q3 and (not q2);

 --When positive edge is detected,
 --it is determined that the button is pressed.
 --When a negative edge is detected,
 --the button is deemed to be released.

 process(clk, rst)
 begin
  if(rst = '0')then
   bcd7_t <= 0;
   bcd6_t <= 0;
   bcd5_t <= 0;
   bcd4_t <= 0;
   bcd3_t <= 0;
   bcd2_t <= 0;
   bcd1_t <= 0;
   bcd0_t <= 0;
  elsif(clk'event and clk = '1') then
   if(diff_np = '1') then
    bcd7_t <= dash;
    bcd6_t <= 0;
    bcd5_t <= 7;
    bcd4_t <= 1;
    bcd3_t <= 5;
    bcd2_t <= 3;
    bcd1_t <= 2;
    bcd0_t <= 6;
   elsif(diff_pp = '1') then
    bcd7_t <= 2;
    bcd6_t <= 0;
    bcd5_t <= dash;
    bcd4_t <= 0;
    bcd3_t <= 4;
    bcd2_t <= dash;
    bcd1_t <= 2;
    bcd0_t <= 3;
   end if;
  end if;
 end process;

 process(clk, rst)
 begin
  if(rst = '0') then
   scan_cnt <= "000";
  elsif(clk'event and clk ='1') then
   if(fq_div = '1') then --counting rate 1ms
    scan_cnt <= scan_cnt+1;
   end if;
  end if;
 end process;

 bcd <= bcd0_t when(scan_cnt = "000") else -- 0
     bcd1_t when(scan_cnt = "001") else
     bcd2_t when(scan_cnt = "010") else
     bcd3_t when(scan_cnt = "011") else
        bcd4_t when(scan_cnt = "100") else
        bcd5_t when(scan_cnt = "101") else
        bcd6_t when(scan_cnt = "110") else
        bcd7_t when(scan_cnt = "111");

 seg_out <= "10010000" when(bcd = 9) else
      "10000000" when(bcd = 8) else
       "11111000" when(bcd = 7) else
      "10000010" when(bcd = 6) else
      "10010010" when(bcd = 5) else
      "10011001" when(bcd = 4) else
      "10110000" when(bcd = 3) else
      "10100100" when(bcd = 2) else
      "11111001" when(bcd = 1) else
      "11000000" when(bcd = 0) else
      "10111111";--dash
end beh;
