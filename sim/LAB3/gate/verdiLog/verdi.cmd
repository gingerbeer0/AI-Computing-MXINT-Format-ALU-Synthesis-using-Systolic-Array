verdiSetActWin -dock widgetDock_<Message>
debImport "-f" "list.f"
wvCreateWindow
wvConvertFile -win $_nWave2 -o \
           "/mnt/home/dice12/dice/proj3/sim/LAB3/gate/result.fsdb.fsdb" \
           "/mnt/home/dice12/dice/proj3/sim/LAB3/gate/result.fsdb"
wvSetPosition -win $_nWave2 {("G1" 0)}
wvOpenFile -win $_nWave2 \
           {/mnt/home/dice12/dice/proj3/sim/LAB3/gate/result.fsdb.fsdb}
wvSetPosition -win $_nWave2 {("G1" 0)}
nMemSetPreference
srcSetDisplayAttr -font {-fromGUI}
srcSetDisplayAttr -annotFont {DejaVu Sans Mono 8}
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcDrag -win $_nTrace1
wvGetSignalOpen -win $_nWave2
wvGetSignalSetScope -win $_nWave2 "/AND4X2_HVT"
verdiSetActWin -win $_nWave2
wvGetSignalSetScope -win $_nWave2 "/TOP_tb"
wvSetPosition -win $_nWave2 {("G1" 12)}
wvSetPosition -win $_nWave2 {("G1" 12)}
wvAddSignal -win $_nWave2 -clear
wvAddSignal -win $_nWave2 -group {"G1" \
{/TOP_tb/CLK} \
{/TOP_tb/RSTN} \
{/TOP_tb/calc\[1:0\]} \
{/TOP_tb/cycle_count_add} \
{/TOP_tb/cycle_count_mult} \
{/TOP_tb/cycle_count_mxint} \
{/TOP_tb/cycle_count_sub} \
{/TOP_tb/log_file} \
{/TOP_tb/mxint_snr} -color ID_RED5 \
{/TOP_tb/snr_add} -color ID_ORANGE5 \
{/TOP_tb/snr_mult} -color ID_YELLOW5 \
{/TOP_tb/snr_sub} -color ID_GREEN5 \
}
wvAddSignal -win $_nWave2 -group {"G2" \
}
wvSelectSignal -win $_nWave2 {( "G1" 1 2 3 4 5 6 7 8 9 10 11 12 )} 
wvSetPosition -win $_nWave2 {("G1" 12)}
wvSetPosition -win $_nWave2 {("G1" 12)}
wvSetPosition -win $_nWave2 {("G1" 12)}
wvAddSignal -win $_nWave2 -clear
wvAddSignal -win $_nWave2 -group {"G1" \
{/TOP_tb/CLK} \
{/TOP_tb/RSTN} \
{/TOP_tb/calc\[1:0\]} \
{/TOP_tb/cycle_count_add} \
{/TOP_tb/cycle_count_mult} \
{/TOP_tb/cycle_count_mxint} \
{/TOP_tb/cycle_count_sub} \
{/TOP_tb/log_file} \
{/TOP_tb/mxint_snr} -color ID_RED5 \
{/TOP_tb/snr_add} -color ID_ORANGE5 \
{/TOP_tb/snr_mult} -color ID_YELLOW5 \
{/TOP_tb/snr_sub} -color ID_GREEN5 \
}
wvAddSignal -win $_nWave2 -group {"G2" \
}
wvSelectSignal -win $_nWave2 {( "G1" 1 2 3 4 5 6 7 8 9 10 11 12 )} 
wvSetPosition -win $_nWave2 {("G1" 12)}
wvGetSignalClose -win $_nWave2
wvSetCursor -win $_nWave2 104435.521448 -snap {("G2" 0)}
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSetCursor -win $_nWave2 2683459.905213 -snap {("G1" 12)}
wvScrollUp -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvSelectGroup -win $_nWave2 {G2}
wvScrollDown -win $_nWave2 0
wvScrollUp -win $_nWave2 1
wvSetCursor -win $_nWave2 2693952.417062 -snap {("G1" 11)}
wvSetCursor -win $_nWave2 2725429.952607 -snap {("G1" 11)}
wvSetCursor -win $_nWave2 2709691.184834 -snap {("G1" 11)}
wvZoom -win $_nWave2 1867667.109005 2625751.090047
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G1" 12 )} 
wvSetSearchMode -win $_nWave2 -analog * 
wvSearchNext -win $_nWave2
wvSetSearchMode -win $_nWave2 -analog * 
wvSearchNext -win $_nWave2
wvSaveSignal -win $_nWave2 \
           "/mnt/home/dice12/dice/proj3/sim/LAB3/gate/verdiLog/novas_autosave.ses.wave.0"
debExit
