<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="o_y" />
        <signal name="XLXN_6" />
        <signal name="i_c" />
        <signal name="i_b" />
        <signal name="i_d" />
        <signal name="i_a" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_c" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_d" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="i_c" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="i_d" name="I0" />
            <blockpin signalname="i_b" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1408" y="624" name="XLXI_1" orien="R0" />
        <instance x="1408" y="896" name="XLXI_2" orien="R0" />
        <instance x="1856" y="768" name="XLXI_3" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1760" y1="800" y2="800" x1="1664" />
            <wire x2="1760" y1="704" y2="800" x1="1760" />
            <wire x2="1856" y1="704" y2="704" x1="1760" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1760" y1="528" y2="528" x1="1664" />
            <wire x2="1760" y1="528" y2="640" x1="1760" />
            <wire x2="1856" y1="640" y2="640" x1="1760" />
        </branch>
        <branch name="o_y">
            <wire x2="2304" y1="672" y2="672" x1="2112" />
        </branch>
        <iomarker fontsize="28" x="2304" y="672" name="o_y" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1120" y1="496" y2="496" x1="1088" />
            <wire x2="1408" y1="496" y2="496" x1="1120" />
        </branch>
        <branch name="i_c">
            <wire x2="1120" y1="560" y2="560" x1="768" />
            <wire x2="1408" y1="560" y2="560" x1="1120" />
        </branch>
        <branch name="i_b">
            <wire x2="1120" y1="768" y2="768" x1="768" />
            <wire x2="1408" y1="768" y2="768" x1="1120" />
        </branch>
        <branch name="i_d">
            <wire x2="1136" y1="832" y2="832" x1="768" />
            <wire x2="1408" y1="832" y2="832" x1="1136" />
        </branch>
        <instance x="864" y="528" name="XLXI_4" orien="R0" />
        <branch name="i_a">
            <wire x2="864" y1="496" y2="496" x1="768" />
        </branch>
        <iomarker fontsize="28" x="768" y="496" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="768" y="560" name="i_c" orien="R180" />
        <iomarker fontsize="28" x="768" y="768" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="768" y="832" name="i_d" orien="R180" />
    </sheet>
</drawing>