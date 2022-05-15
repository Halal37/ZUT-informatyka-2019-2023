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
        <signal name="XLXN_4">
        </signal>
        <signal name="XLXN_5">
        </signal>
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="i_b" />
        <signal name="i_c" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
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
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="i_c" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="i_b" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="i_b" name="I" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="i_c" name="I" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="784" y="864" name="XLXI_1" orien="R0" />
        <instance x="800" y="1344" name="XLXI_2" orien="R0" />
        <instance x="1296" y="1136" name="XLXI_3" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1168" y1="1248" y2="1248" x1="1056" />
            <wire x2="1168" y1="1072" y2="1248" x1="1168" />
            <wire x2="1296" y1="1072" y2="1072" x1="1168" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1168" y1="768" y2="768" x1="1040" />
            <wire x2="1168" y1="768" y2="1008" x1="1168" />
            <wire x2="1296" y1="1008" y2="1008" x1="1168" />
        </branch>
        <branch name="o_y">
            <wire x2="1696" y1="1040" y2="1040" x1="1552" />
        </branch>
        <iomarker fontsize="28" x="1696" y="1040" name="o_y" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="416" y1="800" y2="800" x1="384" />
            <wire x2="784" y1="800" y2="800" x1="416" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="448" y1="1280" y2="1280" x1="432" />
            <wire x2="800" y1="1280" y2="1280" x1="448" />
        </branch>
        <instance x="160" y="832" name="XLXI_4" orien="R0" />
        <instance x="208" y="1312" name="XLXI_5" orien="R0" />
        <branch name="i_b">
            <wire x2="160" y1="800" y2="800" x1="96" />
            <wire x2="96" y1="800" y2="896" x1="96" />
            <wire x2="160" y1="896" y2="896" x1="96" />
            <wire x2="160" y1="896" y2="1056" x1="160" />
            <wire x2="160" y1="1056" y2="1216" x1="160" />
            <wire x2="448" y1="1216" y2="1216" x1="160" />
            <wire x2="800" y1="1216" y2="1216" x1="448" />
            <wire x2="160" y1="1056" y2="1056" x1="96" />
        </branch>
        <branch name="i_c">
            <wire x2="144" y1="736" y2="736" x1="112" />
            <wire x2="208" y1="736" y2="736" x1="144" />
            <wire x2="416" y1="736" y2="736" x1="208" />
            <wire x2="784" y1="736" y2="736" x1="416" />
            <wire x2="144" y1="736" y2="1280" x1="144" />
            <wire x2="208" y1="1280" y2="1280" x1="144" />
        </branch>
        <iomarker fontsize="28" x="96" y="1056" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="112" y="736" name="i_c" orien="R180" />
    </sheet>
</drawing>