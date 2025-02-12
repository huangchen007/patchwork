graph TD
    id1[pastework/steps/__init__.py] 
    id2[pastework/steps/LLM/LLM.py]
    id3[pastework/steps/LLM/typed.py]
    id4[pastework/steps/CallCode2Prompt/CallCode2Prompt.py]
    id5[pastework/steps/CallCode2Prompt/TestCallCode2Prompt.py]
    id6[pastework/steps/CallCode2Prompt/typed.py]
    id7[pastework/steps/GenerateCodeRepositoryEmbeddings/GenerateCodeRepositoryEmbeddings.py]
    id8[pastework/steps/GenerateCodeRepositoryEmbeddings/typed.py]
    id9[pastework/steps/ScanSemgrep/ScanSemgrep.py]
    id10[pastework/steps/ScanSemgrep/typed.py]
    id11[pastework/steps/GetTypescriptTypeInfo/GetTypescriptTypeInfo.py]
    id12[pastework/steps/GetTypescriptTypeInfo/typed.py]
    id13[pastework/steps/ExtractCodeMethodForCommentContexts/ExtractCodeMethodForCommentContexts.py]
    id14[pastework/steps/ExtractCodeMethodForCommentContexts/typed.py]
    id15[pastework/steps/ExtractModelResponse/ExtractModelResponse.py]
    id16[pastework/steps/ExtractModelResponse/typed.py]
    id17[pastework/steps/GenerateEmbeddings/GenerateEmbeddings.py]
    id18[pastework/steps/GenerateEmbeddings/typed.py]
    id19[pastework/steps/PR/PR.py]
    id20[pastework/steps/PR/typed.py]
    id21[pastework/steps/SlackMessage/SlackMessage.py]
    id22[pastework/steps/SlackMessage/typed.py]
    id23[pastework/steps/PreparePR/PreparePR.py]
    id24[pastework/steps/PreparePR/typed.py]
    id25[pastework/steps/ModifyCodeOnce/ModifyCodeOnce.py]
    id26[pastework/steps/ModifyCodeOnce/typed.py]
    id27[pastework/steps/CreatePRComment/CreatePRComment.py]
    id28[pastework/steps/CreatePRComment/typed.py]
    id29[pastework/steps/CallShell/CallShell.py]
    id30[pastework/steps/CallShell/typed.py]
    id31[pastework/steps/FixIssue/FixIssue.py]
    id32[pastework/steps/FixIssue/typed.py]
    id33[pastework/steps/ScanSonar/ScanSonar.py]
    id34[pastework/steps/ScanSonar/typed.py]
    id35[pastework/steps/CreateIssue/CreateIssue.py]
    id36[pastework/steps/CreateIssue/typed.py]
    id37[pastework/steps/FilterBySimilarity/FilterBySimilarity.py]
    id38[pastework/steps/FilterBySimilarity/typed.py]
    id39[pastework/steps/ReadPRDiffs/ReadPRDiffs.py]
    id40[pastework/steps/ReadPRDiffs/typed.py]
    id41[pastework/steps/AgenticLLM/AgenticLLM.py]
    id42[pastework/steps/AgenticLLM/typed.py]
    id43[pastework/steps/CommitChanges/CommitChanges.py]
    id44[pastework/steps/CommitChanges/typed.py]
    id45[pastework/steps/SimplifiedLLMOnce/SimplifiedLLMOnce.py]
    id46[pastework/steps/SimplifiedLLMOnce/typed.py]
    id47[pastework/steps/ExtractPackageManagerFile/TestExtractPackageManagerFile.py]
    id48[pastework/steps/ExtractPackageManagerFile/typed.py]
    id49[pastework/steps/ModifyCode/ModifyCode.py]
    id50[pastework/steps/ModifyCode/typed.py]
    id51[pastework/steps/JoinList/JoinList.py]
    id52[pastework/steps/JoinList/typed.py]
    id53[pastework/steps/CallAPI/CallAPI.py]
    id54[pastework/steps/CallAPI/typed.py]
    id55[pastework/steps/CreatePR/CreatePR.py]
    id56[pastework/steps/CreatePR/typed.py]
    id57[pastework/steps/ReadIssues/ReadIssues.py]
    id58[pastework/steps/ReadIssues/typed.py]
    id59[pastework/steps/ReadFile/ReadFile.py]
    id60[pastework/steps/ReadFile/typed.py]
    id61[pastework/steps/CallLLM/CallLLM.py]
    id62[pastework/steps/CallLLM/typed.py]
    id63[pastework/steps/CallSQL/CallSQL.py]
    id64[pastework/steps/CallSQL/typed.py]
    id65[pastework/steps/ScanDepscan/ScanDepscan.py]
    id66[pastework/steps/ScanDepscan/typed.py]
    id67[pastework/steps/ExtractDiff/ExtractDiff.py]
    id68[pastework/steps/ExtractDiff/typed.py]
    id69[pastework/steps/QueryEmbeddings/QueryEmbeddings.py]
    id70[pastework/steps/QueryEmbeddings/typed.py]
    id71[pastework/steps/SendEmail/SendEmail.py]
    id72[pastework/steps/SendEmail/typed.py]
    id73[pastework/steps/Combine/Combine.py]
    id74[pastework/steps/Combine/typed.py]
    id75[pastework/steps/SimplifiedLLM/SimplifiedLLM.py]
    id76[pastework/steps/SimplifiedLLM/typed.py]
    id77[pastework/steps/ReadPRs/ReadPRs.py]
    id78[pastework/steps/ReadPRs/typed.py]
    id79[pastework/steps/ExtractCodeContexts/ExtractCodeContexts.py]
    id80[pastework/steps/ExtractCodeContexts/typed.py]
    id81[pastework/steps/AnalyzeImpact/AnalyzeImpact.py]
    id82[pastework/steps/AnalyzeImpact/typed.py]
    id83[pastework/steps/PreparePrompt/PreparePrompt.py]
    id84[pastework/steps/PreparePrompt/typed.py]
    id85[pastework/steps/CreateIssueComment/CreateIssueComment.py]
    id86[pastework/steps/CreateIssueComment/typed.py]
    id87[pastework/steps/ExtractCode/ExtractCode.py]
    id88[pastework/steps/ExtractCode/typed.py]

    id43 -- Updates --> id19
    id17 -- Generates --> id7
    id15 -- Extracts --> id2
    id15 -- Extracts --> id62
    id41 -- Utilizes --> id42
    id81 -- Analyzes --> id87
    id87 -- Utilizes --> id15
    id2 -- Utilizes --> id62
    id61 -- Calls --> id62
    id25 -- Utilizes --> id49
    id13 -- Utilizes --> id79
    id9 -- Scans --> id65
    id11 -- Extracts --> id12
    id35 -- Creates --> id36
    id35 -- Creates --> id81
    id55 -- Uses --> id56
    id27 -- Comments --> id28
    id35 -- Analyzes --> id31
    id31 -- Fixes --> id49
    id31 -- Utilizes --> id87
