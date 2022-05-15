<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="o_cout" />
        <signal name="o_s" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="i_a" />
        <signal name="i_b" />
        <signal name="i_cin" />
        <port polarity="Output" name="o_cout" />
        <port polarity="Output" name="o_s" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_cin" />
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
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="i_cin" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_3">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_4">
            <blockpin signalname="i_cin" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="o_s" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin signalname="o_cout" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1088" y="544" name="XLXI_1" orien="R0" />
        <instance x="1712" y="832" name="XLXI_2" orien="R0" />
        <instance x="1120" y="848" name="XLXI_3" orien="R0" />
        <instance x="1680" y="1088" name="XLXI_4" orien="R0" />
        <instance x="2224" y="544" name="XLXI_5" orien="R0" />
        <branch name="o_cout">
            <wire x2="2704" y1="448" y2="448" x1="2480" />
        </branch>
        <branch name="o_s">
            <wire x2="2736" y1="992" y2="992" x1="1936" />
        </branch>
        <iomarker fontsize="28" x="2736" y="992" name="o_s" orien="R0" />
        <iomarker fontsize="28" x="2704" y="448" name="o_cout" orien="R0" />
        <branch name="XLXN_4">
            <wire x2="2096" y1="736" y2="736" x1="1968" />
            <wire x2="2096" y1="480" y2="736" x1="2096" />
            <wire x2="2224" y1="480" y2="480" x1="2096" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1536" y1="752" y2="752" x1="1376" />
            <wire x2="1536" y1="752" y2="960" x1="1536" />
            <wire x2="1680" y1="960" y2="960" x1="1536" />
            <wire x2="1536" y1="704" y2="752" x1="1536" />
            <wire x2="1712" y1="704" y2="704" x1="1536" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1776" y1="448" y2="448" x1="1344" />
            <wire x2="1776" y1="416" y2="448" x1="1776" />
            <wire x2="2224" y1="416" y2="416" x1="1776" />
        </branch>
        <branch name="i_a">
            <wire x2="672" y1="416" y2="416" x1="592" />
            <wire x2="1088" y1="416" y2="416" x1="672" />
            <wire x2="672" y1="416" y2="720" x1="672" />
            <wire x2="1120" y1="720" y2="720" x1="672" />
        </branch>
        <branch name="i_b">
            <wire x2="864" y1="480" y2="480" x1="592" />
            <wire x2="1072" y1="480" y2="480" x1="864" />
            <wire x2="1088" y1="480" y2="480" x1="1072" />
            <wire x2="864" y1="480" y2="784" x1="864" />
            <wire x2="1120" y1="784" y2="784" x1="864" />
        </branch>
        <branch name="i_cin">
            <wire x2="1168" y1="1024" y2="1024" x1="576" />
            <wire x2="1680" y1="1024" y2="1024" x1="1168" />
            <wire x2="1168" y1="1008" y2="1024" x1="1168" />
            <wire x2="1424" y1="1008" y2="1008" x1="1168" />
            <wire x2="1424" y1="768" y2="1008" x1="1424" />
            <wire x2="1712" y1="768" y2="768" x1="1424" />
        </branch>
        <iomarker fontsize="28" x="576" y="1024" name="i_cin" orien="R180" />
        <iomarker fontsize="28" x="592" y="416" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="592" y="480" name="i_b" orien="R180" />
    </sheet>
</drawing>