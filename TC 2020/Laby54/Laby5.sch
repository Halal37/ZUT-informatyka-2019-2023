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
        <signal name="i_b" />
        <signal name="XLXN_5" />
        <signal name="o_yamb" />
        <signal name="o_yarb" />
        <signal name="o_ya_wieksze_b" />
        <signal name="XLXN_9" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="i_a" />
        <port polarity="Input" name="i_b" />
        <port polarity="Output" name="o_yamb" />
        <port polarity="Output" name="o_yarb" />
        <port polarity="Output" name="o_ya_wieksze_b" />
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="xnor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
            <circle r="8" cx="220" cy="-96" />
            <line x2="256" y1="-96" y2="-96" x1="228" />
            <line x2="60" y1="-28" y2="-28" x1="60" />
        </blockdef>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="XLXN_11" name="I1" />
            <blockpin signalname="o_yamb" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_1" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="o_ya_wieksze_b" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="i_b" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="i_a" name="I" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="xnor2" name="XLXI_9">
            <blockpin signalname="i_b" name="I0" />
            <blockpin signalname="i_a" name="I1" />
            <blockpin signalname="o_yarb" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1728" y="384" name="XLXI_2" orien="R0" />
        <instance x="1728" y="976" name="XLXI_3" orien="R0" />
        <instance x="1328" y="944" name="XLXI_4" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1728" y1="912" y2="912" x1="1552" />
        </branch>
        <branch name="i_b">
            <wire x2="1232" y1="912" y2="912" x1="1056" />
            <wire x2="1280" y1="912" y2="912" x1="1232" />
            <wire x2="1328" y1="912" y2="912" x1="1280" />
            <wire x2="1728" y1="320" y2="320" x1="1232" />
            <wire x2="1232" y1="320" y2="912" x1="1232" />
            <wire x2="1728" y1="608" y2="608" x1="1280" />
            <wire x2="1280" y1="608" y2="912" x1="1280" />
        </branch>
        <branch name="o_yamb">
            <wire x2="2000" y1="288" y2="288" x1="1984" />
            <wire x2="2224" y1="288" y2="288" x1="2000" />
        </branch>
        <branch name="o_yarb">
            <wire x2="2224" y1="576" y2="576" x1="1984" />
        </branch>
        <branch name="o_ya_wieksze_b">
            <wire x2="2224" y1="880" y2="880" x1="1984" />
        </branch>
        <iomarker fontsize="28" x="1056" y="912" name="i_b" orien="R180" />
        <iomarker fontsize="28" x="2224" y="288" name="o_yamb" orien="R0" />
        <iomarker fontsize="28" x="2224" y="576" name="o_yarb" orien="R0" />
        <iomarker fontsize="28" x="2224" y="880" name="o_ya_wieksze_b" orien="R0" />
        <instance x="1408" y="288" name="XLXI_7" orien="R0" />
        <branch name="XLXN_11">
            <wire x2="1728" y1="256" y2="256" x1="1632" />
        </branch>
        <branch name="i_a">
            <wire x2="1104" y1="256" y2="256" x1="1024" />
            <wire x2="1104" y1="256" y2="848" x1="1104" />
            <wire x2="1728" y1="848" y2="848" x1="1104" />
            <wire x2="1344" y1="256" y2="256" x1="1104" />
            <wire x2="1408" y1="256" y2="256" x1="1344" />
            <wire x2="1344" y1="256" y2="544" x1="1344" />
            <wire x2="1728" y1="544" y2="544" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="1024" y="256" name="i_a" orien="R180" />
        <instance x="1728" y="672" name="XLXI_9" orien="R0" />
    </sheet>
</drawing>