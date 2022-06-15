library ieee;
use ieee.std_logic_1164.all;

entity lab4 is
port( 
    i:in std_logic_vector(7 downto 0);
    o: out std_logic_vector(6 downto 0)
);
end lab4;

architecture behavioral of lab4 is
begin
    process(i)
    begin
        if i(7) = '1' then o <= "0001111";
        elsif i(6) = '1' then o<="1100000"; 
        elsif i(5) = '1' then o<="0100100";
        elsif i(4) = '1' then o<="1001100";
        elsif i(3) = '1' then o<="0000110";
        elsif i(2) = '1' then o<="0010010";
        elsif i(1) = '1' then o<="1001111";
        elsif i(0) = '1' then o<="0000001";
        else o <="1111111";
        end if;
    end process;

end behavioral;