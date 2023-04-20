#
# Jacob Neiheisel
#
require 'spec_helper'

describe 'C4 standard board size' do
    it 'detects P1 winning horizontally in row 0' do
        # Notice that the game should end before the last 'q' input is consumed
        result = test_c4('aabbccdq')
        expect(result).to declare_win_for 1
    end

    it 'quits before declaring a winner in column 0' do
        result = test_c4('abababq')
        expect(result).to be_abandoned
    end
    it 'lower left corner flat line player 1 wins' do
        result = test_c4('AGBFCED')
        expect(result).to declare_win_for 1
    end
    it 'lower right corner flat line player 1 wins' do
        result = test_c4('GGFFEED')
        expect(result).to declare_win_for 1
    end
    it 'lower left corner point line player 1 wins' do
        result = test_c4('AGAFAEA')
        expect(result).to declare_win_for 1
    end
    it 'lower right corner point line player 1 wins' do
        result = test_c4('GFGFGEG')
        expect(result).to declare_win_for 1
    end
    it 'lower left corner diag player 1 wins' do
        result = test_c4('ABBCCFCEDDDED')
        expect(result).to declare_win_for 1
    end
    it 'lower right corner diag player 1 wins' do
        result = test_c4('GFFEEBEDDDD')
        expect(result).to declare_win_for 1
    end
    it 'mid point line player 1 wins' do
        result = test_c4('ABCDEGFACBDFEGABCDEGFACBFDGEACBEDGFGAFBECD')
        expect(result).to declare_win_for 1
    end
    it 'upper left corner flat line player 2 wins' do
        result = test_c4('ACBDEBFBCCDDADAAEBEC', 4, 6, 4)
        expect(result).to declare_win_for 2
    end

    it 'upper right corner flat line player 2 wins' do
        result = test_c4('gffeeddeddbfceagggaf', 4, 7, 4)
        expect(result).to declare_win_for 2
    end

    it 'upper left corner point line player 2 wins' do
        result = test_c4('acbdegfabcdgefabcdegfbacffgebcaea', 4, 7, 4)
        expect(result).to declare_win_for 2
    end


    it 'upper right corner point line player 1 wins' do
        result = test_c4('acbdeaffggbcdbedcceegcgegeg')
        expect(result).to declare_win_for 1
    end

    it 'upper left corner diag player 1 wins' do
        result = test_c4('acbdegfafcdbggcedfcbfbbbacaaa')
        expect(result).to declare_win_for 1
    end

    it 'upper right corner diag player 2 wins' do
        result = test_c4('afbcfgegedabcdabcdegfabacegfafbgbg')
        expect(result).to declare_win_for 2
    end

    it 'upper mid flat line player 2 wins' do
        result = test_c4('ACBDEGFABCDGEFABCDEFGBCDFEBCDBGCEGFDAE')
        expect(result).to declare_win_for 2
    end

    it 'mid mid flat line player 1 wins' do
        result = test_c4('ACBDEGFABFCGDGE')
        expect(result).to declare_win_for 1
    end
    it 'lower mid flat line player 1 wins' do
        result = test_c4('CADBEGF')
        expect(result).to declare_win_for 1
    end

    it 'mid left low right high diag player 1 wins' do
        result = test_c4('BAECFDBGDCCDDAEFEEEGFGFBG')
        expect(result).to declare_win_for 1
    end

    it 'mid right low left high diag player 2 wins' do
        result = test_c4('BACDEBFDGGFECDAABEGFCCABCBEDEB')
        expect(result).to declare_win_for 2
    end

    it 'mid point line player 1 wins' do
        result = test_c4('ACBDFEEGEAECE')
        expect(result).to declare_win_for 1
    end

    it 'left edge line player 2 wins' do
        result = test_c4('AACAEAGA')
        expect(result).to declare_win_for 2
    end

    it 'right edge line player 2 wins' do
        result = test_c4('GGCGAGEG')
        expect(result).to declare_win_for 2
    end
    it 'left edge start diag player 2 wins' do
        result = test_c4('aabbcbccgceddddd')
        expect(result).to declare_win_for 2
    end
    it 'right edge start diag player 2 wins' do
        result = test_c4('ggffefeeaebddddd')
        expect(result).to declare_win_for 2
    end
#add two more tests (one for horizontal line starting on each edge side)
    it 'right side edge straight line player 2 wins' do
        result = test_c4('ggffddaebe')
        expect(result).to declare_win_for 2
    end

    it 'left side edge straight line player 2 wins' do
        result = test_c4('aabbecfcdd')
        expect(result).to declare_win_for 2
    end
    it 'top edge diag to right side edge player 2 wins' do
        result = test_c4('defgefggddedddfeaebf')
        expect(result).to declare_win_for 2
    end


    it 'top edge diag to left side edge player 2 wins' do
        result = test_c4('badcadbbcacagbccdddd')
        expect(result).to declare_win_for 2
    end

    it 'left side edge diag to bottom player 2 wins' do
        result = test_c4('abcdfabcabga')
        expect(result).to declare_win_for 2
    end
    it 'right side edge diag to bottom player 2 wins' do
        result = test_c4('gfedbefgafgg')
        expect(result).to declare_win_for 2
    end

end


describe 'Connect 4 alternate' do
    it 'detects player 2 winning horizontally on a big board' do
        result = test_c4('iaabbccddeeffgq', 3, 9, 7)
        expect(result).to declare_win_for 2
    end

    it 'quits before declaring a winner in column 0' do
        result = test_c4('iaabbccddeeffq', 3, 9, 7)
        expect(result).to be_abandoned
    end
end

