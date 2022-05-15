<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="i_a" />
        <signal name="i_b" />
        <signal name="i_c" />
        <signal name="y" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
        <port polarity="Output" name="y" />
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
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="i_c" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="y" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="640" y="656" name="XLXI_1" orien="R0" />
        <instance x="1088" y="736" name="XLXI_2" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="992" y1="560" y2="560" x1="896" />
            <wire x2="992" y1="560" y2="608" x1="992" />
            <wire x2="1088" y1="608" y2="608" x1="992" />
        </branch>
        <branch name="i_a">
            <wire x2="640" y1="528" y2="528" x1="336" />
        </branch>
        <branch name="i_b">
            <wire x2="640" y1="592" y2="592" x1="336" />
        </branch>
        <branch name="i_c">
            <wire x2="1088" y1="672" y2="672" x1="336" />
        </branch>
        <branch name="y">
            <wire x2="1520" y1="640" y2="640" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="336" y="528" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="336" y="592" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="336" y="672" name="i_c" orien="R180" />
        <iomarker fontsize="28" x="1520" y="640" name="y" orien="R0" />
    </sheet>
</drawing>