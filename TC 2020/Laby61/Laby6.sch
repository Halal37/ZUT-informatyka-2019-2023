<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="i_d0" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="o_y" />
        <signal name="i_a" />
        <signal name="XLXN_9" />
        <signal name="i_d1" />
        <port polarity="Input" name="i_d0" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_d1" />
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
            <blockpin signalname="i_d0" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="i_d1" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1664" y="608" name="XLXI_1" orien="R0" />
        <instance x="1664" y="912" name="XLXI_2" orien="R0" />
        <instance x="2160" y="768" name="XLXI_3" orien="R0" />
        <instance x="1280" y="432" name="XLXI_4" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1584" y1="400" y2="400" x1="1504" />
            <wire x2="1584" y1="400" y2="480" x1="1584" />
            <wire x2="1664" y1="480" y2="480" x1="1584" />
        </branch>
        <branch name="i_d0">
            <wire x2="1664" y1="544" y2="544" x1="992" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="2032" y1="512" y2="512" x1="1920" />
            <wire x2="2032" y1="512" y2="640" x1="2032" />
            <wire x2="2160" y1="640" y2="640" x1="2032" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2032" y1="816" y2="816" x1="1920" />
            <wire x2="2032" y1="704" y2="816" x1="2032" />
            <wire x2="2160" y1="704" y2="704" x1="2032" />
        </branch>
        <branch name="o_y">
            <wire x2="2560" y1="672" y2="672" x1="2416" />
        </branch>
        <iomarker fontsize="28" x="2560" y="672" name="o_y" orien="R0" />
        <branch name="i_a">
            <wire x2="1072" y1="64" y2="128" x1="1072" />
            <wire x2="1168" y1="128" y2="128" x1="1072" />
            <wire x2="1168" y1="128" y2="400" x1="1168" />
            <wire x2="1280" y1="400" y2="400" x1="1168" />
            <wire x2="1072" y1="128" y2="784" x1="1072" />
            <wire x2="1664" y1="784" y2="784" x1="1072" />
        </branch>
        <branch name="i_d1">
            <wire x2="1664" y1="848" y2="848" x1="992" />
        </branch>
        <iomarker fontsize="28" x="1072" y="64" name="i_a" orien="R270" />
        <iomarker fontsize="28" x="992" y="544" name="i_d0" orien="R180" />
        <iomarker fontsize="28" x="992" y="848" name="i_d1" orien="R180" />
    </sheet>
</drawing>