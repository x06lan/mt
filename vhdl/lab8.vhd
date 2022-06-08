library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity lab8 is
generic(fmax : integer := 5E7);--50MHz
port(--input pins
	clk				:in	std_logic;--pin = 18 , 50MHz
	leds1 :out std_logic_vector(0 to 2);
	leds2 :out std_logic_vector(0 to 2);
	seg7_out1 :out std_logic_vector(0 to 6);
	seg7_out2 :out std_logic_vector(0 to 6)
	);
end lab8;
--*****************************************************************************
--3.Architectures(Body)
architecture beh of lab8 is
	shared variable cnt: integer range 0 to 5E7-1 :=0;
	shared variable cnt_sec: integer range 0 to 3 :=0;
	shared variable  cnt_unit: integer range 0 to 10:=0;
	shared variable redRemaining: integer range 0 to 16 :=0;
begin
	process(clk)
	begin
		if (clk = '1') then
			cnt := cnt+1;
				if (cnt = 5E7-1)then
					cnt := 0;
					cnt_sec := cnt_sec +1;

					if(cnt_sec = 3)then
						cnt_unit := cnt_unit+1;
						cnt_sec := 0;
					end if;
					if(redRemaining=0)then
						redRemaining:=15;
					end if;
					redRemaining :=redRemaining-1;
					if (redRemaining > 9)then
						seg7_out2 <= "1001111";
					else
						seg7_out2 <= "0000001"; --0
					end if;

					case (redRemaining Mod 10) is
				            when 0 =>
				            	seg7_out1 <= "0000001"; --0
				            when 1 =>
				            	seg7_out1 <= "1001111"; ---1
				            when 2 =>
				            	seg7_out1 <= "0010010"; ---2
				            when 3 =>
				            	seg7_out1 <= "0000110"; ---3
				            when 4 =>
				            	seg7_out1 <= "1001100"; ---4
				            when 5 =>
				            	seg7_out1 <= "0100100"; ---5
				            when 6 =>
				            	seg7_out1 <= "0100000"; ---6
				            when 7 =>
				            	seg7_out1 <= "0001111"; ---7
				            when 8 =>
				            	seg7_out1 <= "0000000"; ---8
				            when 9 =>
				            	seg7_out1 <= "0000100"; ---null
				            when others =>
				            	seg7_out1 <= "1111111"; ---null
						end case;

					case cnt_unit is
						when 0 =>
							leds1 <= "100";
							leds2 <= "010";
						when 4 =>
							leds2 <= "001";
						when 5 =>
							leds1 <= "010";
							leds2 <= "100";
						when 9 =>
							leds1 <= "001";
						when others=>

					end case;
					if (cnt_unit = 10)then
						cnt_unit := 0;
					end if;

			end if;
		end if;
	end process;

end beh;