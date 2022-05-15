<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="o_y" />
        <signal name="i_b" />
        <signal name="XLXN_5">
        </signal>
        <signal name="i_a" />
        <signal name="XLXN_7" />
        <signal name="XLXN_9" />
        <port polarity="Output" name="o_y" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_a" />
        <blockdef name="m4_1e">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="96" y1="-416" y2="-416" x1="0" />
            <line x2="96" y1="-352" y2="-352" x1="0" />
            <line x2="96" y1="-288" y2="-288" x1="0" />
            <line x2="96" y1="-224" y2="-224" x1="0" />
            <line x2="96" y1="-32" y2="-32" x1="0" />
            <line x2="256" y1="-320" y2="-320" x1="320" />
            <line x2="96" y1="-160" y2="-160" x1="0" />
            <line x2="96" y1="-96" y2="-96" x1="0" />
            <line x2="96" y1="-96" y2="-96" x1="176" />
            <line x2="176" y1="-208" y2="-96" x1="176" />
            <line x2="96" y1="-32" y2="-32" x1="224" />
            <line x2="224" y1="-216" y2="-32" x1="224" />
            <line x2="96" y1="-224" y2="-192" x1="256" />
            <line x2="256" y1="-416" y2="-224" x1="256" />
            <line x2="256" y1="-448" y2="-416" x1="96" />
            <line x2="96" y1="-192" y2="-448" x1="96" />
            <line x2="96" y1="-160" y2="-160" x1="128" />
            <line x2="128" y1="-200" y2="-160" x1="128" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <block symbolname="m4_1e" name="XLXI_1">
            <blockpin signalname="XLXN_9" name="D0" />
            <blockpin signalname="XLXN_5" name="D1" />
            <blockpin signalname="XLXN_5" name="D2" />
            <blockpin signalname="XLXN_9" name="D3" />
            <blockpin signalname="XLXN_5" name="E" />
            <blockpin signalname="i_a" name="S0" />
            <blockpin signalname="i_b" name="S1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="gnd" name="XLXI_2">
            <blockpin signalname="XLXN_9" name="G" />
        </block>
        <block symbolname="vcc" name="XLXI_3">
            <blockpin signalname="XLXN_5" name="P" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2240" y="768" name="XLXI_1" orien="R0" />
        <branch name="o_y">
            <wire x2="2752" y1="448" y2="448" x1="2560" />
        </branch>
        <branch name="i_b">
            <wire x2="2240" y1="672" y2="672" x1="1776" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1568" y1="240" y2="416" x1="1568" />
            <wire x2="1568" y1="416" y2="472" x1="1568" />
            <wire x2="1568" y1="472" y2="480" x1="1568" />
            <wire x2="1568" y1="480" y2="736" x1="1568" />
            <wire x2="1760" y1="736" y2="736" x1="1568" />
            <wire x2="2240" y1="736" y2="736" x1="1760" />
            <wire x2="2240" y1="480" y2="480" x1="1568" />
            <wire x2="2240" y1="416" y2="416" x1="1568" />
        </branch>
        <branch name="i_a">
            <wire x2="2240" y1="608" y2="608" x1="1776" />
        </branch>
        <iomarker fontsize="28" x="2752" y="448" name="o_y" orien="R0" />
        <iomarker fontsize="28" x="1776" y="608" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="1776" y="672" name="i_b" orien="R180" />
        <instance x="1840" y="1120" name="XLXI_2" orien="R0" />
        <instance x="1504" y="240" name="XLXI_3" orien="R0" />
        <branch name="XLXN_9">
            <wire x2="2240" y1="352" y2="352" x1="1904" />
            <wire x2="1904" y1="352" y2="536" x1="1904" />
            <wire x2="1904" y1="536" y2="544" x1="1904" />
            <wire x2="1904" y1="544" y2="992" x1="1904" />
            <wire x2="2240" y1="544" y2="544" x1="1904" />
        </branch>
    </sheet>
</drawing>