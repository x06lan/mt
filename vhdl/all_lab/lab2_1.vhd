--*****************************************************************************
--1.Libraries Declarations and Packages usage
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
--*****************************************************************************
--2.Entity Declarations
entity lab2_1 is
port(
      clk_1   :in     std_logic;
      S,R     :in     std_logic;
      PR,CLR  :in     std_logic;
      Q       :buffer std_logic
    );
end lab2_1;
--*****************************************************************************
--3.Architectures(Body)
architecture beh of lab2_1 is
--(1)Global Signal's Declaration
    signal RS : std_logic_vector(1 downto 0);--2 Bits
--*****************************************************************************
begin
--system Connections
    RS <= R & S; --Signal : Concatenation operator

    process(clk) --Sensitivity List
    begin
        if( pr = '0')then --Synchronous Preset and Clear
            Q <= '1';
        elsif(CLR ='0')then
            Q <= '0';
        elsif(clk'event and clk = '1')then --Positive-Edge Trigger
            case RS is
                when "00"   =>Q <=   Q; --Qn+1 = Qn : Holding
                when "01"   =>Q <= '1'; --Set
                when "10"   =>Q <= '0'; --Clear
                when others =>null    ; --Forbidden
            end case;
        end if;
    end process;
--*****************************************************************************
end beh;
