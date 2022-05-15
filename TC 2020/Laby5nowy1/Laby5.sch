<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="o_c" />
        <signal name="o_s" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="i_b" />
        <signal name="i_a" />
        <port polarity="Output" name="o_c" />
        <port polarity="Output" name="o_s" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_a" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="o_c" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="o_s" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1632" y="544" name="XLXI_1" orien="R0" />
        <instance x="1632" y="880" name="XLXI_2" orien="R0" />
        <branch name="o_c">
            <wire x2="2160" y1="448" y2="448" x1="1888" />
        </branch>
        <branch name="o_s">
            <wire x2="2176" y1="784" y2="784" x1="1888" />
        </branch>
        <branch name="i_b">
            <wire x2="1120" y1="816" y2="816" x1="688" />
            <wire x2="1632" y1="816" y2="816" x1="1120" />
            <wire x2="1632" y1="480" y2="480" x1="1120" />
            <wire x2="1120" y1="480" y2="816" x1="1120" />
        </branch>
        <branch name="i_a">
            <wire x2="992" y1="416" y2="416" x1="688" />
            <wire x2="1632" y1="416" y2="416" x1="992" />
            <wire x2="992" y1="416" y2="752" x1="992" />
            <wire x2="1632" y1="752" y2="752" x1="992" />
        </branch>
        <iomarker fontsize="28" x="688" y="416" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="688" y="816" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="2160" y="448" name="o_c" orien="R0" />
        <iomarker fontsize="28" x="2176" y="784" name="o_s" orien="R0" />
    </sheet>
</drawing>