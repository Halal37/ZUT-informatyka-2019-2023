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
        <signal name="i_a" />
        <signal name="i_b" />
        <signal name="i_c" />
        <signal name="o_y" />
        <port polarity="Input" name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Input" name="i_c" />
        <port polarity="Output" name="o_y" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
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
        <block symbolname="m4_1e" name="XLXI_1">
            <blockpin signalname="i_a" name="D0" />
            <blockpin signalname="XLXN_1" name="D1" />
            <blockpin signalname="XLXN_2" name="D2" />
            <blockpin signalname="XLXN_3" name="D3" />
            <blockpin signalname="XLXN_1" name="E" />
            <blockpin signalname="i_b" name="S0" />
            <blockpin signalname="i_c" name="S1" />
            <blockpin signalname="o_y" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="vcc" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_4">
            <blockpin signalname="XLXN_3" name="G" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2336" y="800" name="XLXI_1" orien="R0" />
        <instance x="1872" y="544" name="XLXI_2" orien="R0" />
        <instance x="2096" y="176" name="XLXI_3" orien="R0" />
        <instance x="2080" y="1008" name="XLXI_4" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="2160" y1="176" y2="448" x1="2160" />
            <wire x2="2160" y1="448" y2="768" x1="2160" />
            <wire x2="2336" y1="768" y2="768" x1="2160" />
            <wire x2="2336" y1="448" y2="448" x1="2160" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="2336" y1="512" y2="512" x1="2096" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="2336" y1="576" y2="576" x1="2144" />
            <wire x2="2144" y1="576" y2="880" x1="2144" />
        </branch>
        <branch name="i_a">
            <wire x2="1840" y1="384" y2="384" x1="1728" />
            <wire x2="2336" y1="384" y2="384" x1="1840" />
            <wire x2="1840" y1="384" y2="512" x1="1840" />
            <wire x2="1872" y1="512" y2="512" x1="1840" />
        </branch>
        <branch name="i_b">
            <wire x2="2336" y1="640" y2="640" x1="1728" />
        </branch>
        <branch name="i_c">
            <wire x2="2336" y1="704" y2="704" x1="1728" />
        </branch>
        <branch name="o_y">
            <wire x2="2800" y1="480" y2="480" x1="2656" />
        </branch>
        <iomarker fontsize="28" x="2800" y="480" name="o_y" orien="R0" />
        <iomarker fontsize="28" x="1728" y="384" name="i_a" orien="R180" />
        <iomarker fontsize="28" x="1728" y="640" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="1728" y="704" name="i_c" orien="R180" />
    </sheet>
</drawing>