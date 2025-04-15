# 프로젝트 생성 및 설정
set top_module "TOP"
set project_dir ./pj3
new_project $top_module -projectwdir $project_dir -force

# 디자인 파일 읽기
read_file -type sourcelist ./list.f
read_sdc_data -top TOP ./../../syn/LAB3/sdc/TOP.sdc

# 분석 목표 설정
set_goal lint
set_top_module $top_module

set_enabled_rules lint/basic
set_enabled_rules lint/style

# 규칙 설정 (필요에 따라 사용자 정의 규칙 파일 포함)

# 검증 실행
run_goal lint
report_goal lint
# SpyGlass 종료
exit -force
