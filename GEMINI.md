# MultiGAS 세미프로젝트: GAS & Multiplayer 수칙

이 파일은 Gemini CLI가 이 프로젝트 내에서 수행하는 모든 작업에 대한 **최상위 지침**입니다. 모든 구현은 아래의 원칙을 준수해야 합니다.

## 1. 프로젝트 목표 (Project Vision)
- **게임 장르:** 팀 기반 1인칭 슈팅 (FPS)
- **핵심 재미 요소:** 짧은 시간(1~3분) 내의 박진감 넘치는 팀 데스매치.
- **주요 메커니즘:**
  - **팀전:** 두 팀으로 나뉘어 경쟁하며, 상대 팀 플레이어 처치 시 팀 점수 1점 획득.
  - **리스폰:** 사망 시 3초의 대기 시간 후 지정된 장소에서 부활.
  - **무기:** 모든 플레이어에게는 특성이 다른 2종의 무기 지급.
- **핵심 가치:** 단순 기능 구현보다 **확장성 있는 GAS 구조**와 **정확한 네트워크 동기화**를 우선함.
- **학습 포인트:** Gameplay Ability System(GAS)의 깊은 이해와 서버-클라이언트 권한 구조 체득.

## 2. 코딩 표준 및 스타일 (Coding Standards)
- **엔진 준수:** [Unreal Engine C++ Coding Standard](https://dev.epicgames.com/documentation/en-us/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine)를 엄격히 따름.
- **명명 규칙:**
  - **프로젝트 접두어:** 모든 새로운 프로젝트 전용 클래스 및 파일은 `MG`를 접두어로 사용함. (예: `AMGCharacterBase`, `UMGAttributeSet`)
  - 클래스/변수: PascalCase  - GAS 관련 접두사:
    - `GA_`: Gameplay Ability
    - `GE_`: Gameplay Effect
    - `GC_`: Gameplay Cue
    - `GS_`: Gameplay Ability System Component / State
- **주석:** 복잡한 로직이나 네트워크 RPC 호출부에는 반드시 의도를 설명하는 한글 주석을 포함함.

## 3. GAS 및 멀티플레이어 구현 원칙
- **Authority Check:** 상태 변경(HP 감소, 효과 적용 등)은 반드시 `HasAuthority()`를 통해 서버에서 수행함.
- **GAS 구조:** 
  - AttributeSet은 `FGameplayAttributeData`를 사용하여 선언하고, `OnRep_` 함수를 통해 동기화함.
  - Ability는 `InstancingPolicy`를 고려하여 설계함.
- **UI 동기화:** UI 업데이트는 가급적 `AttributeValueChangeDelegate`를 활용하여 이벤트 기반으로 처리함.

## 4. 작업 프로세스 (Workflow)
- **사용자 중심 제어:** 모든 파일 생성 및 코드 수정은 **사용자가 직접 수행**함.
- **Gemini의 역할:** 
  - 설계 가이드 제공, 구현 로직 제안, 코드 스니펫 생성 및 리뷰.
  - 사용자의 명시적인 요청(예: "이 파일을 생성해줘", "이 코드를 수정해줘")이 없는 한, `write_file`이나 `replace` 등 파일을 수정하는 도구를 직접 사용하지 않음.
- **연구(Research):** 기존 코드와의 호환성을 분석하고 보고함.
- **전략(Strategy):** 구현 전, 논리적 구조와 코드를 먼저 제안함.
- **검증(Validation):** 사용자가 구현한 코드의 논리적 오류나 네트워크 동기화 문제를 리뷰함.

## 5. 메모 (User Hints)
- (이곳에 추가적인 규칙이나 개인 선호 사항을 기록하세요.)
