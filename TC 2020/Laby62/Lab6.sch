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
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="o_y" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="i_d0" />
        <signal name="i_d1" />
        <signal name="i_d2" />
        <signal name="i_d3" />
        <signal name="i_a1" />
        <signal name="i_a0" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_d0" />
        <port polarity="Input" name="i_d1" />
        <port polarity="Input" name="i_d2" />
        <port polarity="Input" name="i_d3" />
        <port polarity="Input" name="i_a1" />
        <port polarity="Input" name="i_a0" />
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
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
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <block symbolname="or4" name="XLXI_5">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="XLXN_2" name="I2" />
            <blockpin signalname="XLXN_1" name="I3" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin signalname="i_a0" name="I" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="i_a1" name="I" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_8">
            <blockpin signalname="i_d3" name="I0" />
            <blockpin signalname="i_a1" name="I1" />
            <blockpin signalname="i_a0" name="I2" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_10">
            <blockpin signalname="i_d1" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="i_a0" name="I2" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_11">
            <blockpin signalname="i_d0" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="XLXN_11" name="I2" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_12">
            <blockpin signalname="i_d2" name="I0" />
            <blockpin signalname="i_a1" name="I1" />
            <blockpin signalname="XLXN_11" name="I2" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2496" y="1056" name="XLXI_5" orien="R0" />
        <instance x="1376" y="288" name="XLXI_6" orien="R0" />
        <instance x="1408" y="448" name="XLXI_7" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="2496" y1="544" y2="544" x1="2144" />
            <wire x2="2496" y1="544" y2="800" x1="2496" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="2320" y1="768" y2="768" x1="2144" />
            <wire x2="2320" y1="768" y2="864" x1="2320" />
            <wire x2="2496" y1="864" y2="864" x1="2320" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="2160" y1="1024" y2="1024" x1="2144" />
            <wire x2="2320" y1="1024" y2="1024" x1="2160" />
            <wire x2="2320" y1="928" y2="1024" x1="2320" />
            <wire x2="2496" y1="928" y2="928" x1="2320" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2496" y1="1264" y2="1264" x1="2144" />
            <wire x2="2496" y1="992" y2="1264" x1="2496" />
        </branch>
        <branch name="o_y">
            <wire x2="3008" y1="896" y2="896" x1="2752" />
        </branch>
        <instance x="1888" y="1392" name="XLXI_8" orien="R0" />
        <instance x="1888" y="896" name="XLXI_10" orien="R0" />
        <instance x="1888" y="672" name="XLXI_11" orien="R0" />
        <instance x="1888" y="1152" name="XLXI_12" orien="R0" />
        <branch name="XLXN_11">
            <wire x2="1792" y1="256" y2="256" x1="1600" />
            <wire x2="1888" y1="256" y2="256" x1="1792" />
            <wire x2="1888" y1="256" y2="480" x1="1888" />
            <wire x2="1792" y1="256" y2="960" x1="1792" />
            <wire x2="1888" y1="960" y2="960" x1="1792" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1664" y1="416" y2="416" x1="1632" />
            <wire x2="1760" y1="416" y2="416" x1="1664" />
            <wire x2="1760" y1="416" y2="544" x1="1760" />
            <wire x2="1888" y1="544" y2="544" x1="1760" />
            <wire x2="1664" y1="416" y2="768" x1="1664" />
            <wire x2="1888" y1="768" y2="768" x1="1664" />
        </branch>
        <branch name="i_d0">
            <wire x2="1888" y1="608" y2="608" x1="1456" />
        </branch>
        <branch name="i_d1">
            <wire x2="1888" y1="832" y2="832" x1="1456" />
        </branch>
        <branch name="i_d2">
            <wire x2="1888" y1="1088" y2="1088" x1="1456" />
        </branch>
        <branch name="i_d3">
            <wire x2="1888" y1="1328" y2="1328" x1="1440" />
        </branch>
        <iomarker fontsize="28" x="1456" y="608" name="i_d0" orien="R180" />
        <iomarker fontsize="28" x="1456" y="832" name="i_d1" orien="R180" />
        <iomarker fontsize="28" x="1456" y="1088" name="i_d2" orien="R180" />
        <iomarker fontsize="28" x="1440" y="1328" name="i_d3" orien="R180" />
        <iomarker fontsize="28" x="3008" y="896" name="o_y" orien="R0" />
        <branch name="i_a1">
            <wire x2="1328" y1="416" y2="416" x1="1152" />
            <wire x2="1408" y1="416" y2="416" x1="1328" />
            <wire x2="1328" y1="416" y2="512" x1="1328" />
            <wire x2="1600" y1="512" y2="512" x1="1328" />
            <wire x2="1600" y1="512" y2="1024" x1="1600" />
            <wire x2="1888" y1="1024" y2="1024" x1="1600" />
            <wire x2="1328" y1="512" y2="512" x1="1280" />
            <wire x2="1280" y1="512" y2="1264" x1="1280" />
            <wire x2="1888" y1="1264" y2="1264" x1="1280" />
        </branch>
        <branch name="i_a0">
            <wire x2="1216" y1="256" y2="256" x1="1152" />
            <wire x2="1376" y1="256" y2="256" x1="1216" />
            <wire x2="1216" y1="256" y2="336" x1="1216" />
            <wire x2="1216" y1="336" y2="704" x1="1216" />
            <wire x2="1888" y1="704" y2="704" x1="1216" />
            <wire x2="1216" y1="704" y2="1200" x1="1216" />
            <wire x2="1888" y1="1200" y2="1200" x1="1216" />
        </branch>
        <iomarker fontsize="28" x="1152" y="256" name="i_a0" orien="R180" />
        <iomarker fontsize="28" x="1152" y="416" name="i_a1" orien="R180" />
    </sheet>
</drawing>