--****************************************************************************
-- Lab Title : Two SWs and 8 BCD Counter to 8 Digits 7-Segment Display
-- School    : Daan_High_school()
-- Author    :
-- CPLD      : Altera MAX II EPM1270T44C5
-- Data      : 109-06-11
--****************************************************************************
--1.libraries Declarations and Packages usage
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
--*****************************************************************************
--2.Entity Declarations
entity lab8 is
generic(fmax : integer := 5E7);--50MHz
port(--input pins
	clk				:in	std_logic;--pin = 18 , 50MHz
	rst_n			:in	std_logic;--pin = 61
	start_sw		:in	std_logic;--pin = 102
	stop_sw		:in	std_logic;--pin = 97
	dip_sw			:in	std_logic;--pin = 21
	--output pins
	sw_gnd	:out	std_logic;--pin = 103
	buzzer		:out	std_logic;--pin = 96
	scan			:out	std_logic_vector(7 downto 0);--pin = 144 ~ 137(active low)
	seg_out	:out	std_logic_vector(7 downto 0)--Commoc-Anode(active low)
	);
end lab8;
--*****************************************************************************
--3.Architectures(Body)
architecture beh of lab8 is
	--(1)Global Signal's Declarations
	---------------------------------------------------------------------------
	-- i.System's Signals
	signal rst					:std_logic;--active low
	signal sample_p		:std_logic;
	signal clk_1				:std_logic;
	signal clk_1p			:std_logic;
	signal clk_100p		:std_logic;
	signal clk_2k			:std_logic;
	signal clk_2kp			:std_logic;
	signal flag_flash		:std_logic;
	signal flag_buzzer 	:std_logic;
	-------------------------------------------------------
	--00 Clear , 01 Start , 10 Continue , 11 Stop
	signal flags				:std_logic_vector(1 downto 0);
	---------------------------------------------------------------------------
	--ii. SW's Debouncer Circuit Signals
	signal sw_in				:std_logic_vector(1 downto 0);--length = number of SWs
	signal q1,q0				:std_logic_vector(1 downto 0);--length = number of SWs
	signal q3,q2				:std_logic_vector(1 downto 0);--length = number of SWs
	signal flat					:std_logic_vector(1 downto 0);--length = number of SWs
	signal diff_pp			:std_logic_vector(1 downto 0);--length = number of SWs
	signal diff_np			:std_logic_vector(1 downto 0);--length = number of SWs
	---------------------------------------------------------------------------
	--iii. 8Digits 7-Seg Display Signals
	signal scan_cnt		:std_logic_vector(2 downto 0);--3Bits
	signal cnt_5s			:std_logic_vector(3 downto 0);--4Bits
	---------------------------------------------------------------------------
	--iv. Data Register Signals
	signal bcd				:std_logic_vector(3 downto 0);--4Bits (for MUX Register)
	---------------------------------------------------------------------------
	--v. 8 Digits BCD Counter Signals
	signal bcd7				:std_logic_vector(3 downto 0);--4Bits 10Hr
	signal bcd6				:std_logic_vector(3 downto 0);--4Bits 1Hr
	signal bcd5				:std_logic_vector(3 downto 0);--4Bits 10Min
	signal bcd4				:std_logic_vector(3 downto 0);--4Bits 1Min
	signal bcd3				:std_logic_vector(3 downto 0);--4Bits 10s
	signal bcd2				:std_logic_vector(3 downto 0);--4Bits 1s
	signal bcd1				:std_logic_vector(3 downto 0);--4Bits 0.1s
	signal bcd0				:std_logic_vector(3 downto 0);--4Bits 0.01s
	---------------------------------------------------------------------------
	--vi. 8 Digits Data Latch Signals
	signal bcd7L			:std_logic_vector(3 downto 0);--4Bits 10Hr
	signal bcd6L			:std_logic_vector(3 downto 0);--4Bits 1Hr
	signal bcd5L			:std_logic_vector(3 downto 0);--4Bits 10Min
	signal bcd4L			:std_logic_vector(3 downto 0);--4Bits 1Min
	signal bcd3L			:std_logic_vector(3 downto 0);--4Bits 10s
	signal bcd2L			:std_logic_vector(3 downto 0);--4Bits 1s
	signal bcd1L			:std_logic_vector(3 downto 0);--4Bits 0.1s
	signal bcd0L			:std_logic_vector(3 downto 0);--4Bits 0.01s
	---------------------------------------------------------------------------
	--vii. 8 Groups MUX Signals
	signal bcd7x			:std_logic_vector(3 downto 0);--4Bits 10Hr
	signal bcd6x			:std_logic_vector(3 downto 0);--4Bits 1Hr
	signal bcd5x			:std_logic_vector(3 downto 0);--4Bits 10Min
	signal bcd4x			:std_logic_vector(3 downto 0);--4Bits 1Min
	signal bcd3x			:std_logic_vector(3 downto 0);--4Bits 10s
	signal bcd2x			:std_logic_vector(3 downto 0);--4Bits 1s
	signal bcd1x			:std_logic_vector(3 downto 0);--4Bits 0.1s
	signal bcd0x			:std_logic_vector(3 downto 0);--4Bits 0.01s
	signal temp				:std_logic_vector(7 downto 0);--for Flashing
-------------------------------------------------------------------------------
begin
	--System Connections
	sw_gnd <= '0'; --connected to Gnd

	buzzer	 <= '1'	  	 when(dip_sw 		= '1')else --off
					  '1'		 when(flag_buzzer  = '0')else --off
					  clk_2k ;
	---------------------------------------------------------------------------
	--1. Frequency Divider's Signals
	process(clk) --Sensitivity List
		variable cnt0 : std_logic_vector(22 downto 0); --23bits
		variable cnt1 : std_logic_vector(15 downto 0); --16bits
		variable cnt2 : std_logic_vector(19 downto 0); --20bits
		variable cnt3 : std_logic_vector(25 downto 0); --26bits
		variable cnt4 : std_logic_vector(14 downto 0); --15bits
	begin
		if(rst_n = '0')then -- Asynchronous Reset (Initializations)
			cnt0 := (others => '0');
			cnt2 := (others => '0');
			cnt4 := (others => '0');
		elsif(clk'event and clk = '1')then -- Positive Edge Trigger (20nS)
			-------------------------------------------------------------------
			--(1)Generate System's Global Reset Signal = Power on : 100mS
			if(cnt0 < fmax / 10 - 1)then
				cnt0 := cnt0 + 1;
				rst	<= '0';
			else
				rst	<= '1';
			end if;
			-------------------------------------------------------------------
			--(2) Generate SW's Sample Pulse Cricuit : Frequency = 1k Hz
			if(cnt1 < fmax / 1E3 - 1)then --Denominator = Output Frequency for test
				cnt1				:= cnt1 + 1;
				sample_p	<= '0';
			else
				cnt1				:= (others => '0');
				sample_p	<= '1';
			end if;
			-------------------------------------------------------------------
			--(3)Generate 100Hz Pulse Cricuit
			if(cnt2 < fmax / 5E5 - 1)then --Denominator = Output Frequency
				cnt2				:= cnt2 + 1;
				clk_100p		<= '0';
			else
				cnt2				:= (others => '0');
				clk_100p		<= '1';
			end if;
			-------------------------------------------------------------------
			--(4)Generate 1Hz Square Wave Cricuit
			if(cnt3 < fmax / 2 - 1)then
				cnt3				:= cnt3 + 1;
				clk_1			<= '0';
				clk_1p			<= '0';
			elsif(cnt3 < fmax / 1 - 1)then --Denominator = Output Frequency
				cnt3				:= cnt3 + 1;
				clk_1			<= '1';
				clk_1p			<= '0';
			else
				cnt3				:= (others => '0');
				clk_1			<= '0';
				clk_1p			<= '1';
			end if;
			-------------------------------------------------------------------
			--(5)Generate 2KHz Piled and Square Wav Circuit for Buzzer
			if(cnt4 < fmax / 4E3 - 1)then
				cnt4				:= cnt4 + 1;
				clk_2k			<= '0';
				clk_2kp		<= '0';
			elsif(cnt4 < fmax / 2E3 - 1)then--Denominator = Output Frequency
				cnt4				:= cnt4 + 1;
				clk_2k			<= '1';
				clk_2kp		<= '0';
			else
				cnt4				:= (others => '0');--clear
				clk_2k			<= '0';
				clk_2kp		<= '1';
			end if;
		end if;
	end process;
	---------------------------------------------------------------------------
	--2. SW's Sampling , Debouncer an Differential Circuits
	---------------------------------------------------------------------------
	--(0) Tact SW's Concatenation
	sw_in <= start_sw & stop_sw;--Signals Concatenation
	--(1) Sampling Circuit
	process(clk,rst)--Sensitivity Reset
	begin
		if(rst = '0')then --Asynchronous Reset
			q1 <= "00";
			q0 <= "00";
		elsif(clk'event and clk = '1')then --Positive Edge Trigger (20nS)
			if(sample_p = '1')then --Sampling Rate = 1mS
				q1	<= q0;
				q0	<= sw_in; --input signal write here
				flat	<= ((q0 or q1) and flat) or (q0 and q1); --RS-FF(1)
			end if;
		end if;
	end process;
	---------------------------------------------------------------------------
	--(2) Shift-Register Circuit
	process(clk,rst)--Sensitivity Reset
	begin
		if(rst = '0')then --Asynchronous Reset
			q3 <= "00";
			q2 <= "00";
		elsif(clk'event and clk = '1')then --Positive Edge Trigger (20nS)
			q3	<= q2;
			q2	<= flat; --differential input signal write here
		end if;
	end process;
	---------------------------------------------------------------------------
	--(3) Differential Circuits (Global Signals) (Tw = 20ns)
	diff_pp <=(not 	q3) and (			q2); --Catch Positive-Edge Pulse
	diff_np <=(		q3) and (not 	q2); --Catch Negative-Edge Pulse
	---------------------------------------------------------------------------
	--3.SW's Status Detector Circuit
	process(clk,rst)--Sensitivity List
		variable cnt_buzzer : integer range 0 to 511;
	begin
		if(rst = '0')then -- Asynchronous Reset (Initialization)
			flags				<= "11";--Stop Mode
			cnt_5s				<= "0000";
			flag_flash			<= '1';
			flag_buzzer 		<= '0';
			cnt_buzzer		:=	   0;
		elsif(clk'event and clk = '1')then --Positive Edge Trigger (20nS)
			-------------------------------------------------------------------
			--(1)Sratt SW Detector Circuit
			if(diff_np(1) = '1')then --Start SW's NEgative-Edge (Pressed)
				flag_buzzer 	<= '1';
				flag_flash		<= '1';
				if(flags   = "11")then
				   flags <= "00"; --Clear Mode
				elsif(flags   = "01")then
					    flags <= "10"; --Continue
				end if;
			elsif(diff_pp(1) = '1')then --Sratt SW's Positive-Edge : Start (released)
				flag_buzzer 	<= '1';
				flag_flash		<= '1';
				if(flags = "00")then
					flags <= "01"; --Start Mode
				end if;
			end if;
			-------------------------------------------------------------------
			--(2)Stop SW Detector Circuit
			if(diff_np(0) = '1')then
				flag_buzzer 	<= '1';
				flag_flash		<= '1';
				flags				<= "11"; --Stop Mode
			end if;
			-------------------------------------------------------------------
			--(3)Count 5 Sec.
			if(flags = "11" and clk_1p = '1')then
				if(cnt_5s < 5)then
					cnt_5s <= cnt_5s+1;
					flag_flash <= '0';
				else
					flag_flash <= '1';
				end if;
			end if;
			-------------------------------------------------------------------
			--(4)Buzzer Control Circuit
			if(flag_buzzer = '1' and clk_2kp = '1')then
				if(cnt_buzzer < 400)then -- 400 x 0.5 ms = 0.2s
					cnt_buzzer := cnt_buzzer + 1;
				else
					flag_buzzer 		<= '0';
					cnt_buzzer		:= 0;
				end if;
			end if;
		end if;
	end process;
	---------------------------------------------------------------------------
	--4. 8 Digits BCD Counters
	process(clk,rst)--Sensitivity List
	begin
		if(rst = '0')then -- Asynchronous Reset (Initialization)
			bcd7 <= "0001";--1 (ID or Data)
			bcd6 <= "0000";--0
			bcd5 <= "1001";--9
			bcd4 <= "1011";-- -
			bcd3 <= "0000";--0
			bcd2 <= "0110";--6
			bcd1 <= "0001";--1
			bcd0 <= "1000";--8
		elsif(clk'event and clk = '1')then --Positive Edge Trigger (20ns)
			-------------------------------------------------------------------
			--(1)System Flags Check
			if(flags="00")then --clear Mode
				bcd7 <= "0000";
				bcd6 <= "0000";
				bcd5 <= "0000";
				bcd4 <= "0000";
				bcd3 <= "0000";
				bcd2 <= "0000";
				bcd1 <= "0000";
				bcd0 <= "0000";
			-------------------------------------------------------------------
			--(2)Start Counting
		elsif((flags="01" or flags="10") and clk_100p = '1')then
					if(bcd0 = 9)then
							bcd0<="0000";
							if(bcd1 = 9)then
								bcd1<="0000";
									if(bcd2 = 9)then
									bcd2<="0000";
										if(bcd3 = 5)then
										bcd3<="0000";
											if(bcd4 = 9)then
											bcd4<="0000";
												if(bcd5 = 5)then
													bcd5<="0000";
													if(bcd7<2 and bcd6 = 9)or(bcd7 = 2 and bcd6 = 3) then
														bcd6<="0000";
														if(bcd7 = 2 and bcd6 = 3)then
															bcd7<="0000";
											else
												bcd7<= bcd7+1;
											end if;
										else
											bcd6<=bcd6+1;
										end if;
									else
										bcd5<=bcd5+1;
									end if;
								else
									bcd4<=bcd4+1;
								end if;
							else
								bcd3<=bcd3+1;
							end if;
						else
							bcd2<=bcd2+1;
						end if;
					else
						bcd1<=bcd1+1;
					end if;
				else
					bcd0<=bcd0+1;
				end if;
			end if;
		end if;
	end process;
		-----------------------------------------------------------------------
		--5. Data Latch
		process(clk, rst)
		begin
			if(rst = '0')then --Asynchronous Reset (Initialization)
				bcd7L<="0000";
				bcd6L<="0000";
				bcd5L<="0000";
				bcd4L<="0000";
				bcd3L<="0000";
				bcd2L<="0000";
				bcd1L<="0000";
				bcd0L<="0000";
			elsif(clk'event and clk = '1')then --Positive Edge Trigger(20ns)
				-------------------------------------------------------------------
				--(1)Sratt SW Detector Circuit
				if((flags = "01" or flags = "10") and diff_np(1) = '1')then
					bcd7L <= bcd7;
					bcd6L <= bcd6;
					bcd5L <= bcd5;
					bcd4L <= bcd4;
					bcd3L <= bcd3;
					bcd2L <= bcd2;
					bcd1L <= bcd1;
					bcd0L <= bcd0;
				elsif(flags = "11")then
					bcd7L<="0000";
					bcd6L<="0000";
					bcd5L<="0000";
					bcd4L<="0000";
					bcd3L<="0000";
					bcd2L<="0000";
					bcd1L<="0000";
					bcd0L<="0000";
				end if;
			end if;
		end process;
		-----------------------------------------------------------------------
		--6.Mulit-Scan Counter
		process (clk, rst)--Sensitivity List
		begin
			if(rst = '0')then --Asynchronous Reset
				scan_cnt <= "000";
			elsif(clk'event and clk = '1') then --Positive Edge Trigger(20ns)
				if(sample_p = '1') then--Counting Rate = 1ms
					scan_cnt <= scan_cnt +1;
				end if;
			end if;
		end process;
		-----------------------------------------------------------------------
		--7.8 Digits 7-Segment Display Flashing Cirucuits (including 5 Sub-circuits)
			-------------------------------------------------------------------
			--(1)3 to 8 Decoder : Generate Scanning Code(active low)
			--Digit		76543210
			scan <= 	"11111110"when(scan_cnt = "000") else
							"11111101"when(scan_cnt = "001") else
							"11111011"when(scan_cnt = "010") else
							"11110111"when(scan_cnt = "011") else
							"11101111"when(scan_cnt = "100") else
							"11011111"when(scan_cnt = "101") else
							"10111111"when(scan_cnt = "110") else
							"01111111";
			-------------------------------------------------------------------
			--(2)8 Group 4 Bits 2 to 1 MUX : Data Latch or Data Sources Select
			bcd7x <= bcd7L when(flags = "10") else
							bcd7;

			bcd6x <= bcd6L when(flags = "10") else
							bcd6;

			bcd5x <= bcd5L when(flags = "10") else
							bcd5;

			bcd4x <= bcd4L when(flags = "10") else
							bcd4;

			bcd3x <= bcd3L when(flags = "10") else
							bcd3;

			bcd2x <= bcd2L when(flags = "10") else
							bcd2;

			bcd1x <= bcd1L when(flags = "10") else
							bcd1;

			bcd0x <= bcd0L when(flags = "10") else
							bcd0;
			-------------------------------------------------------------------
			--(3)4Bits 8 to 1 MUX : Data Source Select
			bcd <= bcd0x when (scan_cnt = "000") else--0
						bcd1x when (scan_cnt = "001") else--1
						bcd2x when (scan_cnt = "010") else--2
						bcd3x when (scan_cnt = "011") else--3
						bcd4x when (scan_cnt = "100") else--4
						bcd5x when (scan_cnt = "101") else--5
						bcd6x when (scan_cnt = "110") else--6
						bcd7x;--7
			-------------------------------------------------------------------
			--(4)BCD to 7Segment Display Decoder : Common-Anode(active low)
				--dpgfedcba
			temp <=	"10010000" when (bcd = "1001") else--9
							"10000000" when (bcd = "1000") else
							"11111000" when (bcd = "0111") else
							"10000010" when (bcd = "0110") else
							"10010010" when (bcd = "0101") else
							"10011001" when (bcd = "0100") else
							"10110000" when (bcd = "0011") else
							"10100100" when (bcd = "0010") else
							"11111001" when (bcd = "0001") else
							"11000000" when (bcd = "0000") else--0
							"10111001" when (bcd = "1010") else--10:+
							"10111111" when (bcd = "1011") else--11:-
							"10110111" when (bcd = "1100") else
							"11110111" when (bcd = "1101") else
							"10011101" when (bcd = "1110") else
							"10101011";
			-------------------------------------------------------------------
			--(5)Digits Flashing Control Circuit(LED : on-> active low)
			seg_out(7) <= (temp(7) and clk_1)when(scan_cnt = "010")else--2
														 	 '0' when(scan_cnt = "100" or scan_cnt = "110")else --4-6
																temp(7);
			seg_out(6) <= (temp(6) or clk_1)when(flags = "00"or flag_flash = '0')else temp(6);
			seg_out(5) <= (temp(5) or clk_1)when(flags = "00"or flag_flash = '0')else temp(5);
			seg_out(4) <= (temp(4) or clk_1)when(flags = "00"or flag_flash = '0')else temp(4);
			seg_out(3) <= (temp(3) or clk_1)when(flags = "00"or flag_flash = '0')else temp(3);
			seg_out(2) <= (temp(2) or clk_1)when(flags = "00"or flag_flash = '0')else temp(2);
			seg_out(1) <= (temp(1) or clk_1)when(flags = "00"or flag_flash = '0')else temp(1);
			seg_out(0) <= (temp(0) or clk_1)when(flags = "00"or flag_flash = '0')else temp(0);
	--*************************************************************************
	end beh;
