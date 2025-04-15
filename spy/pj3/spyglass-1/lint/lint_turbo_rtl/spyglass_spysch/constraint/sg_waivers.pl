################################################################################
#This is an internally genertaed by spyglass to populate Waiver Info for Reports
#Note:Spyglass does not support any perl routine like "spyDecompileWaiverInfo"
#     The routine is purely for internal usage of spyglass
################################################################################


use SpyGlass;

spyClearWaiverHashInPerl(0);

spyComputeWaivedViolCount("totalWaivedViolationCount"=>'0',
                          "totalGeneratedCount"=>'238',
                          "totalReportCount"=>'238'
                         );

spyComputeViolCountForTurbo("totalGeneratedCount"=>'238',
                          "totalGeneratedSecCount"=>'27211',
                          "totalWaivedPrimaryMsgCount"=>'0',
                          "totalWaivedSecMsgCount"=>'0',
                         );

spyWaiversDataCount("totalWaivers"=>'0',
"totalWaiversApplied"=>'0',
"totalWaiversWithRegExp"=>'0',
"totalWaiversWithRuleSpecified"=>'0',
"totalWaiversWithIpSpecified"=>'0',
"totalWaiversWithFileLine"=>'0',
                         );

spyProhibitWaiverRules(                         );

spySetWaivedViolationNumberHash("");

1;
