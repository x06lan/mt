--*****************************************************************************
--1.Libraries Declarations and Packages usage
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
--*****************************************************************************
--2.Entity Declarations
entity lab2_2 is
generic(fmax : integer := 5E7);
port(
      clk     :in      std_logic;

      wave_s  :out     std_logic;
      wave_P  :out     std_logic
    );
end lab2_2;
--*****************************************************************************
--3.Architectures(Body)
architecture beh of lab2_2 is
--(1)Global Signal's Declaration

--*****************************************************************************
begin
--system Connections

--*****************************************************************************
    --1.100KHz Square Wave(10uS/20nS=500)
    process(clk) --Sensitivity List
        variable ant_S : std_logic_vector(8 downto 0); --9 Bits
    begin
        if(clk'event and clk = '1')then --Positive-Edge Trigger
            if(cnt_S <fmax/200E3 - 1)then
                wave_s <= '0';
                cnt_S   :=cnt_S + 1;
            elsif(cnt_S <fmax/100E3 - 1)then

                wave_s <= '1';
                cnt_S   :=cnt_S + 1;
            else
                wave_s <= '0';
                cnt_S   :=(other => '0'); --clear
            end if;
        end if;
    end process;
--*****************************************************************************
    --2.100KHz Pulsed Wave(10uS/20nS=500)
    process(clk) --Sensitivity List
        variable ant_p : std_logic_vector(8 downto 0); --9 Bits
    begin
        if(clk'event and clk = '1')then --Positive-Edge Trigger
            if(cnt_p <fmax/200E3 - 1)then
                wave_p <= '0';
                cnt_p   :=cnt_p + 1;
            else
                wave_p <= '0';
                cnt_p   :=(other => '0'); --clear
            end if;
        end if;
    end process;
--*****************************************************************************
end beh;
