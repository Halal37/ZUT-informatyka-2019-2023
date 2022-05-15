<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="o_vout" />
        <signal name="o_d" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="i_vin" />
        <signal name="XLXN_8" />
        <signal name="i_b" />
        <signal name="XLXN_10" />
        <signal name="i_a" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <port polarity="Output" name="o_vout" />
        <port polarity="Output" name="o_d" />
        <port polarity="Input" name="i_vin" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_a" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
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
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="o_vout" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_3">
            <blockpin signalname="XLXN_14" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="o_d" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_4">
            <blockpin signalname="i_vin" name="I0" />
            <blockpin signalname="i_b" name="I1" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_14" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="i_vin" name="I0" />
            <blockpin signalname="i_b" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="832" y="368" name="XLXI_1" orien="R0" />
        <instance x="2464" y="512" name="XLXI_2" orien="R0" />
        <instance x="2464" y="1024" name="XLXI_3" orien="R0" />
        <instance x="1536" y="1088" name="XLXI_4" orien="R0" />
        <instance x="1776" y="480" name="XLXI_5" orien="R0" />
        <instance x="1792" y="704" name="XLXI_6" orien="R0" />
        <branch name="o_vout">
            <wire x2="2928" y1="416" y2="416" x1="2720" />
        </branch>
        <branch name="o_d">
            <wire x2="2944" y1="928" y2="928" x1="2720" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2464" y1="384" y2="384" x1="2032" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="2256" y1="608" y2="608" x1="2048" />
            <wire x2="2256" y1="448" y2="608" x1="2256" />
            <wire x2="2464" y1="448" y2="448" x1="2256" />
        </branch>
        <branch name="i_vin">
            <wire x2="1296" y1="1024" y2="1024" x1="912" />
            <wire x2="1536" y1="1024" y2="1024" x1="1296" />
            <wire x2="1792" y1="640" y2="640" x1="1296" />
            <wire x2="1296" y1="640" y2="1024" x1="1296" />
        </branch>
        <branch name="i_b">
            <wire x2="1168" y1="576" y2="576" x1="864" />
            <wire x2="1792" y1="576" y2="576" x1="1168" />
            <wire x2="1168" y1="576" y2="960" x1="1168" />
            <wire x2="1536" y1="960" y2="960" x1="1168" />
        </branch>
        <branch name="i_a">
            <wire x2="736" y1="336" y2="336" x1="576" />
            <wire x2="832" y1="336" y2="336" x1="736" />
            <wire x2="736" y1="336" y2="896" x1="736" />
            <wire x2="2464" y1="896" y2="896" x1="736" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1408" y1="336" y2="336" x1="1056" />
            <wire x2="1408" y1="336" y2="352" x1="1408" />
            <wire x2="1776" y1="352" y2="352" x1="1408" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="1776" y1="416" y2="416" x1="1696" />
            <wire x2="1696" y1="416" y2="720" x1="1696" />
            <wire x2="1824" y1="720" y2="720" x1="1696" />
            <wire x2="1824" y1="720" y2="992" x1="1824" />
            <wire x2="2128" y1="992" y2="992" x1="1824" />
            <wire x2="1824" y1="992" y2="992" x1="1792" />
            <wire x2="2128" y1="960" y2="992" x1="2128" />
            <wire x2="2464" y1="960" y2="960" x1="2128" />
        </branch>
        <iomarker fontsize="28" x="2928" y="416" name="o_vout" orien="R0" />
        <iomarker fontsize="28" x="2944" y="928" name="o_d" orien="R0" />
        <iomarker fontsize="28" x="576" y="336" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="864" y="576" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="912" y="1024" name="i_vin" orien="R180" />
    </sheet>
</drawing>