<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="i_a" />
        <signal name="o_y" />
        <signal name="XLXN_30" />
        <signal name="i_b" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="i_c" />
        <signal name="XLXN_40" />
        <signal name="XLXN_41" />
        <signal name="XLXN_42" />
        <signal name="XLXN_43" />
        <signal name="XLXN_44" />
        <signal name="i_d" />
        <signal name="XLXN_46" />
        <signal name="XLXN_47" />
        <port polarity="Input" name="i_a" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
        <port polarity="Input" name="i_d" />
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
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="XLXN_15" name="I0" />
            <blockpin signalname="XLXN_14" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="XLXN_16" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="XLXN_19" name="I0" />
            <blockpin signalname="XLXN_18" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_21" name="I0" />
            <blockpin signalname="XLXN_20" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="XLXN_30" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="i_d" name="I0" />
            <blockpin signalname="i_c" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="i_d" name="I0" />
            <blockpin signalname="XLXN_36" name="I1" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_11">
            <blockpin signalname="XLXN_44" name="I0" />
            <blockpin signalname="i_c" name="I1" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_12">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_18" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_13">
            <blockpin signalname="i_d" name="I0" />
            <blockpin signalname="i_c" name="I1" />
            <blockpin signalname="XLXN_19" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_14">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="XLXN_20" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_15">
            <blockpin signalname="i_d" name="I0" />
            <blockpin signalname="XLXN_37" name="I1" />
            <blockpin signalname="XLXN_21" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_16">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_17">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_18">
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_19">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_20">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_21">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_22">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_23">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_24">
            <blockpin signalname="i_b" name="I" />
            <blockpin signalname="XLXN_30" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_25">
            <blockpin signalname="i_c" name="I" />
            <blockpin signalname="XLXN_37" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_26">
            <blockpin signalname="i_c" name="I" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_27">
            <blockpin signalname="i_d" name="I" />
            <blockpin signalname="XLXN_44" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1072" y="480" name="XLXI_1" orien="R0" />
        <instance x="1072" y="848" name="XLXI_2" orien="R0" />
        <instance x="1072" y="1152" name="XLXI_3" orien="R0" />
        <instance x="1072" y="1472" name="XLXI_4" orien="R0" />
        <instance x="1088" y="1792" name="XLXI_5" orien="R0" />
        <instance x="640" y="368" name="XLXI_6" orien="R0" />
        <instance x="640" y="544" name="XLXI_7" orien="R0" />
        <instance x="656" y="752" name="XLXI_8" orien="R0" />
        <instance x="656" y="928" name="XLXI_9" orien="R0" />
        <instance x="672" y="1072" name="XLXI_10" orien="R0" />
        <instance x="672" y="1216" name="XLXI_11" orien="R0" />
        <instance x="688" y="1376" name="XLXI_12" orien="R0" />
        <instance x="704" y="1536" name="XLXI_13" orien="R0" />
        <instance x="704" y="1728" name="XLXI_14" orien="R0" />
        <instance x="704" y="1856" name="XLXI_15" orien="R0" />
        <instance x="1520" y="640" name="XLXI_16" orien="R0" />
        <instance x="1568" y="1632" name="XLXI_17" orien="R0" />
        <instance x="1936" y="1344" name="XLXI_18" orien="R0" />
        <instance x="2304" y="1024" name="XLXI_19" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="2032" y1="544" y2="544" x1="1776" />
            <wire x2="2032" y1="544" y2="896" x1="2032" />
            <wire x2="2304" y1="896" y2="896" x1="2032" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2240" y1="1248" y2="1248" x1="2192" />
            <wire x2="2240" y1="960" y2="1248" x1="2240" />
            <wire x2="2304" y1="960" y2="960" x1="2240" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1872" y1="1536" y2="1536" x1="1824" />
            <wire x2="1872" y1="1280" y2="1536" x1="1872" />
            <wire x2="1936" y1="1280" y2="1280" x1="1872" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1632" y1="1056" y2="1056" x1="1328" />
            <wire x2="1632" y1="1056" y2="1216" x1="1632" />
            <wire x2="1936" y1="1216" y2="1216" x1="1632" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1440" y1="1376" y2="1376" x1="1328" />
            <wire x2="1440" y1="1376" y2="1504" x1="1440" />
            <wire x2="1568" y1="1504" y2="1504" x1="1440" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1456" y1="1696" y2="1696" x1="1344" />
            <wire x2="1456" y1="1568" y2="1696" x1="1456" />
            <wire x2="1568" y1="1568" y2="1568" x1="1456" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1344" y1="384" y2="384" x1="1328" />
            <wire x2="1344" y1="384" y2="512" x1="1344" />
            <wire x2="1520" y1="512" y2="512" x1="1344" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1424" y1="752" y2="752" x1="1328" />
            <wire x2="1424" y1="576" y2="752" x1="1424" />
            <wire x2="1520" y1="576" y2="576" x1="1424" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="976" y1="272" y2="272" x1="896" />
            <wire x2="976" y1="272" y2="352" x1="976" />
            <wire x2="1072" y1="352" y2="352" x1="976" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="976" y1="448" y2="448" x1="896" />
            <wire x2="976" y1="416" y2="448" x1="976" />
            <wire x2="1072" y1="416" y2="416" x1="976" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="992" y1="656" y2="656" x1="912" />
            <wire x2="992" y1="656" y2="720" x1="992" />
            <wire x2="1072" y1="720" y2="720" x1="992" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="992" y1="832" y2="832" x1="912" />
            <wire x2="992" y1="784" y2="832" x1="992" />
            <wire x2="1072" y1="784" y2="784" x1="992" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="992" y1="976" y2="976" x1="928" />
            <wire x2="992" y1="976" y2="1024" x1="992" />
            <wire x2="1072" y1="1024" y2="1024" x1="992" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="992" y1="1120" y2="1120" x1="928" />
            <wire x2="992" y1="1088" y2="1120" x1="992" />
            <wire x2="1072" y1="1088" y2="1088" x1="992" />
        </branch>
        <branch name="XLXN_18">
            <wire x2="1008" y1="1280" y2="1280" x1="944" />
            <wire x2="1008" y1="1280" y2="1344" x1="1008" />
            <wire x2="1072" y1="1344" y2="1344" x1="1008" />
        </branch>
        <branch name="XLXN_19">
            <wire x2="1008" y1="1440" y2="1440" x1="960" />
            <wire x2="1008" y1="1408" y2="1440" x1="1008" />
            <wire x2="1072" y1="1408" y2="1408" x1="1008" />
        </branch>
        <branch name="XLXN_20">
            <wire x2="1024" y1="1632" y2="1632" x1="960" />
            <wire x2="1024" y1="1632" y2="1664" x1="1024" />
            <wire x2="1088" y1="1664" y2="1664" x1="1024" />
        </branch>
        <branch name="XLXN_21">
            <wire x2="1024" y1="1760" y2="1760" x1="960" />
            <wire x2="1024" y1="1728" y2="1760" x1="1024" />
            <wire x2="1088" y1="1728" y2="1728" x1="1024" />
        </branch>
        <instance x="368" y="272" name="XLXI_20" orien="R0" />
        <instance x="400" y="656" name="XLXI_21" orien="R0" />
        <instance x="400" y="976" name="XLXI_22" orien="R0" />
        <instance x="432" y="1280" name="XLXI_23" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="688" y1="1248" y2="1248" x1="656" />
        </branch>
        <branch name="XLXN_25">
            <wire x2="672" y1="944" y2="944" x1="624" />
        </branch>
        <branch name="XLXN_26">
            <wire x2="640" y1="624" y2="624" x1="624" />
            <wire x2="656" y1="624" y2="624" x1="640" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="640" y1="240" y2="240" x1="592" />
        </branch>
        <branch name="i_a">
            <wire x2="272" y1="240" y2="240" x1="192" />
            <wire x2="368" y1="240" y2="240" x1="272" />
            <wire x2="272" y1="240" y2="624" x1="272" />
            <wire x2="400" y1="624" y2="624" x1="272" />
            <wire x2="272" y1="624" y2="944" x1="272" />
            <wire x2="400" y1="944" y2="944" x1="272" />
            <wire x2="272" y1="944" y2="1248" x1="272" />
            <wire x2="272" y1="1248" y2="1600" x1="272" />
            <wire x2="704" y1="1600" y2="1600" x1="272" />
            <wire x2="432" y1="1248" y2="1248" x1="272" />
        </branch>
        <iomarker fontsize="28" x="192" y="240" name="i_a" orien="R180" />
        <branch name="o_y">
            <wire x2="2688" y1="928" y2="928" x1="2560" />
        </branch>
        <iomarker fontsize="28" x="2688" y="928" name="o_y" orien="R0" />
        <instance x="384" y="336" name="XLXI_24" orien="R0" />
        <branch name="XLXN_30">
            <wire x2="640" y1="304" y2="304" x1="608" />
        </branch>
        <branch name="i_b">
            <wire x2="224" y1="304" y2="304" x1="192" />
            <wire x2="384" y1="304" y2="304" x1="224" />
            <wire x2="224" y1="304" y2="688" x1="224" />
            <wire x2="656" y1="688" y2="688" x1="224" />
            <wire x2="224" y1="688" y2="1008" x1="224" />
            <wire x2="672" y1="1008" y2="1008" x1="224" />
            <wire x2="224" y1="1008" y2="1312" x1="224" />
            <wire x2="688" y1="1312" y2="1312" x1="224" />
            <wire x2="224" y1="1312" y2="1664" x1="224" />
            <wire x2="704" y1="1664" y2="1664" x1="224" />
        </branch>
        <iomarker fontsize="28" x="192" y="304" name="i_b" orien="R180" />
        <instance x="464" y="1760" name="XLXI_25" orien="R0" />
        <instance x="416" y="832" name="XLXI_26" orien="R0" />
        <branch name="XLXN_36">
            <wire x2="656" y1="800" y2="800" x1="640" />
        </branch>
        <branch name="XLXN_37">
            <wire x2="704" y1="1728" y2="1728" x1="688" />
        </branch>
        <branch name="i_c">
            <wire x2="192" y1="416" y2="416" x1="176" />
            <wire x2="640" y1="416" y2="416" x1="192" />
            <wire x2="192" y1="416" y2="800" x1="192" />
            <wire x2="416" y1="800" y2="800" x1="192" />
            <wire x2="192" y1="800" y2="1088" x1="192" />
            <wire x2="672" y1="1088" y2="1088" x1="192" />
            <wire x2="192" y1="1088" y2="1408" x1="192" />
            <wire x2="704" y1="1408" y2="1408" x1="192" />
            <wire x2="192" y1="1408" y2="1728" x1="192" />
            <wire x2="464" y1="1728" y2="1728" x1="192" />
        </branch>
        <iomarker fontsize="28" x="176" y="416" name="i_c" orien="R180" />
        <instance x="416" y="1184" name="XLXI_27" orien="R0" />
        <branch name="XLXN_44">
            <wire x2="672" y1="1152" y2="1152" x1="640" />
        </branch>
        <branch name="i_d">
            <wire x2="304" y1="480" y2="480" x1="160" />
            <wire x2="304" y1="480" y2="864" x1="304" />
            <wire x2="656" y1="864" y2="864" x1="304" />
            <wire x2="384" y1="480" y2="480" x1="304" />
            <wire x2="384" y1="480" y2="1152" x1="384" />
            <wire x2="416" y1="1152" y2="1152" x1="384" />
            <wire x2="560" y1="480" y2="480" x1="384" />
            <wire x2="624" y1="480" y2="480" x1="560" />
            <wire x2="640" y1="480" y2="480" x1="624" />
            <wire x2="624" y1="480" y2="512" x1="624" />
            <wire x2="560" y1="432" y2="432" x1="320" />
            <wire x2="560" y1="432" y2="480" x1="560" />
            <wire x2="320" y1="432" y2="1472" x1="320" />
            <wire x2="704" y1="1472" y2="1472" x1="320" />
            <wire x2="624" y1="512" y2="512" x1="368" />
            <wire x2="368" y1="512" y2="1792" x1="368" />
            <wire x2="704" y1="1792" y2="1792" x1="368" />
        </branch>
        <iomarker fontsize="28" x="160" y="480" name="i_d" orien="R180" />
    </sheet>
</drawing>