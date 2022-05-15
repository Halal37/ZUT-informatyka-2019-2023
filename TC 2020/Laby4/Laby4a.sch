<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="i_a" />
        <signal name="XLXN_31" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="i_b" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="i_c" />
        <signal name="o_y" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
        <port polarity="Output" name="o_y" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="or2" name="XLXI_1">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="XLXN_29" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="i_c" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_4">
            <blockpin signalname="XLXN_24" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="XLXN_28" name="I1" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_6">
            <blockpin signalname="XLXN_25" name="I0" />
            <blockpin signalname="XLXN_15" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="XLXN_16" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="i_c" name="I" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_10">
            <blockpin signalname="i_c" name="I" />
            <blockpin signalname="XLXN_29" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_13">
            <blockpin signalname="i_b" name="I" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_14">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="816" y="768" name="XLXI_1" orien="R0" />
        <instance x="1328" y="928" name="XLXI_2" orien="R0" />
        <instance x="800" y="1216" name="XLXI_3" orien="R0" />
        <instance x="1328" y="1360" name="XLXI_4" orien="R0" />
        <instance x="880" y="1648" name="XLXI_5" orien="R0" />
        <instance x="1296" y="1872" name="XLXI_6" orien="R0" />
        <instance x="1952" y="1152" name="XLXI_7" orien="R0" />
        <instance x="2480" y="1552" name="XLXI_8" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="2448" y1="1056" y2="1056" x1="2208" />
            <wire x2="2448" y1="1056" y2="1424" x1="2448" />
            <wire x2="2480" y1="1424" y2="1424" x1="2448" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2400" y1="1776" y2="1776" x1="1552" />
            <wire x2="2400" y1="1488" y2="1776" x1="2400" />
            <wire x2="2480" y1="1488" y2="1488" x1="2400" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1248" y1="672" y2="672" x1="1072" />
            <wire x2="1248" y1="672" y2="800" x1="1248" />
            <wire x2="1328" y1="800" y2="800" x1="1248" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1200" y1="1120" y2="1120" x1="1056" />
            <wire x2="1200" y1="1120" y2="1232" x1="1200" />
            <wire x2="1328" y1="1232" y2="1232" x1="1200" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="1200" y1="1552" y2="1552" x1="1136" />
            <wire x2="1200" y1="1552" y2="1664" x1="1200" />
            <wire x2="1200" y1="1664" y2="1664" x1="1136" />
            <wire x2="1136" y1="1664" y2="1744" x1="1136" />
            <wire x2="1296" y1="1744" y2="1744" x1="1136" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="1840" y1="832" y2="832" x1="1584" />
            <wire x2="1840" y1="832" y2="1024" x1="1840" />
            <wire x2="1952" y1="1024" y2="1024" x1="1840" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="1856" y1="1264" y2="1264" x1="1584" />
            <wire x2="1856" y1="1088" y2="1264" x1="1856" />
            <wire x2="1952" y1="1088" y2="1088" x1="1856" />
        </branch>
        <instance x="624" y="1840" name="XLXI_9" orien="R0" />
        <instance x="448" y="1696" name="XLXI_10" orien="R0" />
        <instance x="416" y="1328" name="XLXI_13" orien="R0" />
        <instance x="448" y="896" name="XLXI_14" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="1328" y1="1296" y2="1296" x1="640" />
        </branch>
        <branch name="XLXN_25">
            <wire x2="1296" y1="1808" y2="1808" x1="848" />
        </branch>
        <branch name="XLXN_28">
            <wire x2="736" y1="864" y2="864" x1="672" />
            <wire x2="736" y1="864" y2="960" x1="736" />
            <wire x2="736" y1="960" y2="960" x1="672" />
            <wire x2="672" y1="960" y2="1520" x1="672" />
            <wire x2="880" y1="1520" y2="1520" x1="672" />
        </branch>
        <branch name="XLXN_29">
            <wire x2="752" y1="1664" y2="1664" x1="672" />
            <wire x2="752" y1="864" y2="1664" x1="752" />
            <wire x2="1328" y1="864" y2="864" x1="752" />
        </branch>
        <branch name="i_a">
            <wire x2="240" y1="640" y2="640" x1="128" />
            <wire x2="320" y1="640" y2="640" x1="240" />
            <wire x2="816" y1="640" y2="640" x1="320" />
            <wire x2="320" y1="640" y2="864" x1="320" />
            <wire x2="448" y1="864" y2="864" x1="320" />
            <wire x2="240" y1="640" y2="1072" x1="240" />
            <wire x2="240" y1="1072" y2="1088" x1="240" />
            <wire x2="800" y1="1088" y2="1088" x1="240" />
        </branch>
        <branch name="i_b">
            <wire x2="176" y1="1296" y2="1296" x1="112" />
            <wire x2="224" y1="1296" y2="1296" x1="176" />
            <wire x2="416" y1="1296" y2="1296" x1="224" />
            <wire x2="176" y1="1296" y2="1584" x1="176" />
            <wire x2="880" y1="1584" y2="1584" x1="176" />
            <wire x2="816" y1="704" y2="704" x1="224" />
            <wire x2="224" y1="704" y2="1296" x1="224" />
        </branch>
        <iomarker fontsize="28" x="112" y="1296" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="128" y="640" name="i_a" orien="R180" />
        <branch name="i_c">
            <wire x2="256" y1="1808" y2="1808" x1="160" />
            <wire x2="384" y1="1808" y2="1808" x1="256" />
            <wire x2="624" y1="1808" y2="1808" x1="384" />
            <wire x2="448" y1="1664" y2="1664" x1="256" />
            <wire x2="256" y1="1664" y2="1808" x1="256" />
            <wire x2="800" y1="1152" y2="1152" x1="384" />
            <wire x2="384" y1="1152" y2="1808" x1="384" />
        </branch>
        <iomarker fontsize="28" x="160" y="1808" name="i_c" orien="R180" />
        <branch name="o_y">
            <wire x2="2768" y1="1456" y2="1456" x1="2736" />
        </branch>
        <iomarker fontsize="28" x="2768" y="1456" name="o_y" orien="R0" />
    </sheet>
</drawing>