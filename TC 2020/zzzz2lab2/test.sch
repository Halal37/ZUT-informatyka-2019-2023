<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="i_a" />
        <signal name="i_b" />
        <signal name="i_c" />
        <signal name="XLXN_4" />
        <signal name="o_y" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
        <port polarity="Output" name="o_y" />
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
        <block symbolname="xor2" name="XLXI_1">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="i_c" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="704" name="XLXI_1" orien="R0" />
        <instance x="976" y="880" name="XLXI_2" orien="R0" />
        <branch name="i_a">
            <wire x2="624" y1="576" y2="576" x1="432" />
        </branch>
        <branch name="i_b">
            <wire x2="624" y1="640" y2="640" x1="432" />
        </branch>
        <branch name="i_c">
            <wire x2="976" y1="816" y2="816" x1="432" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="960" y1="608" y2="608" x1="880" />
            <wire x2="960" y1="608" y2="752" x1="960" />
            <wire x2="976" y1="752" y2="752" x1="960" />
        </branch>
        <branch name="o_y">
            <wire x2="1376" y1="784" y2="784" x1="1232" />
        </branch>
        <iomarker fontsize="28" x="1376" y="784" name="o_y" orien="R0" />
        <iomarker fontsize="28" x="432" y="576" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="432" y="640" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="432" y="816" name="i_c" orien="R180" />
    </sheet>
</drawing>