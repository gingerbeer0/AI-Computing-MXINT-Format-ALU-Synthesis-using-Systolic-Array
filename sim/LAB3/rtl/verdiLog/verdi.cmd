verdiSetActWin -dock widgetDock_<Message>
debImport "-f" "list.f"
wvCreateWindow
wvConvertFile -win $_nWave2 -o \
           "/home/jhpark/dice/syn1/sim/LAB3/rtl/result.fsdb.fsdb" \
           "/home/jhpark/dice/syn1/sim/LAB3/rtl/result.fsdb"
wvSetPosition -win $_nWave2 {("G1" 0)}
wvOpenFile -win $_nWave2 {/home/jhpark/dice/syn1/sim/LAB3/rtl/result.fsdb.fsdb}
wvSetPosition -win $_nWave2 {("G1" 0)}
nMemSetPreference
srcSetDisplayAttr -font {-fromGUI}
srcSetDisplayAttr -annotFont {DejaVu Sans Mono 8}
wvGetSignalOpen -win $_nWave2
wvGetSignalSetScope -win $_nWave2 "/TB_FREQDIVCHAIN"
verdiWindowResize -win $_Verdi_1 "270" "130" "900" "700"
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcDrag -win $_nTrace1
verdiSetActWin -win $_nWave2
wvGetSignalSetScope -win $_nWave2 "/TB_FREQDIVCHAIN/DUT/UFDIV2B"
wvSetPosition -win $_nWave2 {("G1" 5)}
wvSetPosition -win $_nWave2 {("G1" 5)}
wvAddSignal -win $_nWave2 -clear
wvAddSignal -win $_nWave2 -group {"G1" \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/CLK} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/CNT\[1:0\]} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/EN} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/OUT} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/RSTN} \
}
wvAddSignal -win $_nWave2 -group {"G2" \
}
wvSelectSignal -win $_nWave2 {( "G1" 1 2 3 4 5 )} 
wvSetPosition -win $_nWave2 {("G1" 5)}
wvSetPosition -win $_nWave2 {("G1" 5)}
wvSetPosition -win $_nWave2 {("G1" 5)}
wvAddSignal -win $_nWave2 -clear
wvAddSignal -win $_nWave2 -group {"G1" \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/CLK} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/CNT\[1:0\]} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/EN} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/OUT} \
{/TB_FREQDIVCHAIN/DUT/UFDIV2B/RSTN} \
}
wvAddSignal -win $_nWave2 -group {"G2" \
}
wvSelectSignal -win $_nWave2 {( "G1" 1 2 3 4 5 )} 
wvSetPosition -win $_nWave2 {("G1" 5)}
wvGetSignalClose -win $_nWave2
wvSetCursor -win $_nWave2 1201885.331950 -snap {("G2" 0)}
wvZoomAll -win $_nWave2
wvSaveSignal -win $_nWave2 \
           "/home/jhpark/dice/syn1/sim/LAB3/rtl/verdiLog/novas_autosave.ses.wave.0"
debExit
