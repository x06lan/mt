--**********************************************************************************
-- Lab Title : RGB LED + PWM + Tact SWs + Buzzer + 3 Digits SSD Circuit
-- School    : Daan_High_school()
-- Author    :
-- CPLD      : Altera MAX II EPM1270T44C5
-- Data      : 109-05-07
--**********************************************************************************
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity lab5 is
  generic(fmax : integer := 5E7);
  port(
    clk : in std_logic;
    rst : in std_logic;
    sw_r : in std_logic;
    sw_g : in std_logic;
    sw_b : in std_logic;

    seg_out : out std_logic_vector(7 downto 0);
    scan : out std_logic_vector (2 downto 0);
    kb_en : out std_logic;
    buzzer : out std_logic;
    rgb_en : out std_logic;
    led_r : out std_logic;
    led_g : out std_logic;
    led_b : out std_logic
    );
  end lab5;

  architecture arch of lab5 is
    signal cnt1 : std_logic_vector(19 downto 0);
    signal cnt2 : std_logic_vector(19 downto 0);
    signal sample_p :std_logic;
    signal clk_2k : std_logic;
    signal clk_2kp : std_logic;
    type pwm_arr is array(0 to 10) of std_logic;
    signal pwm :pwm_arr;
    signal sw_in :std_logic_vector (2 downto 0);
    signal q0, q1 :std_logic_vector (2 downto 0);
    signal q2, q3 :std_logic_vector (2 downto 0);
    signal flat :std_logic_vector (2 downto 0);
    signal diff_pp :std_logic_vector (2 downto 0);
    signal diff_np :std_logic_vector (2 downto 0);

    signal bcd_r : integer range 0 to 15;
    signal bcd_g : integer range 0 to 15;
    signal bcd_b : integer range 0 to 15;
    signal digit : integer range 0 to 15;

    signal scan_cnt :integer range 0 to 3;

    signal cnt_buzzer : integer range 0 to 511;

    signal flag_buzzer : std_logic;
  begin
    rgb_en <= '0';
    kb_en <='0';
    sw_in <= sw_r & sw_g & sw_b;
    buzzer <= '1' when(flag_buzzer = '0') else clk_2k;

    process(clk)
      variable cnt_S : std_logic_vector(8 downto 0);
    begin
      if (rst = '0') then
        cnt1 <= (others => '0');
        cnt2 <= (others => '0');
      elsif (clk'event and clk = '1') then
        if (cnt1 < fmax / 1E3-1) then
          sample_p <= '0';
          cnt1 <= cnt1 + 1;
        else
          sample_p <= '1';
          cnt1 <= (others => '0');
        end if;

        if cnt2 < fmax / 4E3-1 then
          sample_p <= '0';
          cnt2 <= cnt2 + 1;
          clk_2k <= '0';
          clk_2kp <= '0';
        elsif cnt2 < fmax / 2E3 - 1 then
          cnt2 <= cnt2 +1;
          clk_2k <= '1';
          clk_2kp <='0';
        else
          clk_2k <= '0';
          clk_2kp <='1';
          cnt2 <= (others => '0');
        end if;
      end if;
    end process;
    pwm(0) <='0';
    pwm(1) <='1' when (cnt1 <  5000) else '0';
    pwm(2) <='1' when (cnt1 < 10000) else '0';
    pwm(3) <='1' when (cnt1 < 15000) else '0';
    pwm(4) <='1' when (cnt1 < 20000) else '0';
    pwm(5) <='1' when (cnt1 < 25000) else '0';
    pwm(6) <='1' when (cnt1 < 30000) else '0';
    pwm(7) <='1' when (cnt1 < 35000) else '0';
    pwm(8) <='1' when (cnt1 < 40000) else '0';
    pwm(9) <='1' when (cnt1 < 45000) else '0';
    pwm(10) <='1';

    process(clk, rst)
    begin
      if rst = '0' then
        flat <= (others => '0');
      elsif (clk'event and clk = '1') then
        if sample_p = '1' then
          q1 <= q0;
          q0 <= sw_in;
          flat <= (q0 and q1) or ((q0 or q1) and flat);
        end if;
      end if;
    end process;

    process(clk, rst)
    begin
      if rst = '0' then
        q2 <= (others => '0');
        q3<= (others => '0');
      elsif (clk'event and clk = '1') then
        q3 <= q2;
        q2 <= flat;
      end if;
    end process;

    diff_pp <= (not q3) and q2;
    diff_np <= (not q2) and Q3;
    -- 4~5.RGB LEDs Level Counter and Buzzer Control Circuit
    process(clk,rst)
    begin
    	if(rst='0')then
    		bcd_r<=0;
    		bcd_g<=0;
    		bcd_b<=0;
    		flag_buzzer<='0';
    		cnt_buzzer<=0;
    	elsif(clk'event and clk ='1')then --Positive Edge Trigger
    		------------------------------------------------------
    		--(1)Check Sws Pressed
    		if(diff_np(2)='1')then --sw_r:pressed
    			flag_buzzer<='1';
    			if(bcd_r<10)then
    				bcd_r<=bcd_r+1;
    			else
    				bcd_r<=0;
    			end if;
    		end if;
    		if(diff_np(1)='1')then --sw_g:pressed
    			flag_buzzer<='1';
    			if(bcd_g<10)then
    				bcd_g<=bcd_g+1;
    			else
    				bcd_g<=0;
    			end if;
    		end if;
    		if(diff_np(0)='1')then --sw_b:pressed
    			flag_buzzer<='1';
    			if(bcd_b<10)then
    				bcd_b<=bcd_b+1;
    			else
    				bcd_b<=0;
    			end if;
    		end if;
    		------------------------------------------------------
    		--(2) Buzzer Control Circuit
    		if(flag_buzzer='1'and clk_2kp='1')then
    			if(cnt_buzzer<400)then --400 x 0.5 mS = 0.2S
    				cnt_buzzer<=cnt_buzzer+1;
    			else
    				flag_buzzer<='0';
    				cnt_buzzer<=0;
    			end if;
    		end if;
    	end if;
    end process;
    -------------------------------------------------------------
    --6.Multi_scanning Circuit
    -------------------------------------------------------------
    --(1)2bITS Scanning Counter
    process(clk)
    begin
    	if(clk'event and clk='1')then --Positive Edge Trigger
    		if(sample_p='1')then --Scanning Rate = 1mS
    			if(scan_cnt<2)then
    				scan_cnt<=scan_cnt+1;
    			else
    				scan_cnt<=0;
    			end if;
    		end if;
    	end if;
    end process;
    ------------------------------------------------------------
    --(2)2 to 3 Decoder for scanning
    scan<=	"110"when(scan_cnt=0)else --digit_b
    		"101"when(scan_cnt=1)else --digit_g
    		"011";					  --digit_r
    ------------------------------------------------------------
    --(3)3 Digits 4 to 1 MUX
    digit<= bcd_b when(scan_cnt=0)else --digit_b
    		bcd_g when(scan_cnt=1)else --digit_g
    		bcd_r;					   --digit_r
    ------------------------------------------------------------

--
    seg_out <= "11000000" when digit = 0 else
               "11111001" when digit = 1 else
               "10100100" when digit = 2 else
               "10110000" when digit = 3 else
               "10011001" when digit = 4 else
               "10010010" when digit = 5 else
               "10000010" when digit = 6 else
               "11011000" when digit = 7 else
               "10000000" when digit = 8 else
               "10010000" when digit = 9 else
               "10100000";
    led_r <= not pwm(bcd_r);
    led_g <= not pwm(bcd_g);
    led_b <= not pwm(bcd_b);
  end arch;
