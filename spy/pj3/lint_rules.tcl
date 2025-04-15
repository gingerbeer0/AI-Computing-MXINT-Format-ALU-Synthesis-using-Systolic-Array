# Lint 규칙 로드
 set_rule_configuration lint_rules
#
# # 기본 제공 규칙 활성화
 set_enabled_rules lint/basic  # 기본 Lint 규칙 활성화
 set_enabled_rules lint/style  # 코딩 스타일 관련 규칙 활성화
set_enabled_rules lint/performance  # 성능 관련 규칙 활성화
#
# # 특정 규칙 비활성화 (필요 시)
set_disabled_rules lint/basic/rule_name  # 특정 규칙 비활성화 예제
#
# # 사용자 정의 규칙 추가 (선택 사항)
 add_custom_rule -name my_custom_rule -description "Custom rule example"
#
# # 보고서 설정
 set_report_options -level all -format text
#
