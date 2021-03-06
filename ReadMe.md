# Frok Game Server Engine

Frok Game Server Engine은 범용적인 게임 서버를 만들어보기 위해서 만들어진 프로젝트입니다.

## 특징

- 게임과 서버와 통신을 위해 필요한 모듈이 담긴 Core 라이브러리를 제공합니다.
- ProtoBuf를 이용해서 Packet를 좀 더 편하게 개발할 수 있습니다.
- 활용 예제를 위한 Game Server가 프로젝트가 존재합니다.
- 서버의 패킷 송수신의 테스트를 할 수 있게 만든 Dummy Client 프로젝트가 프로젝트가 존재합니다.
- [적용 영상](https://youtu.be/K531u_vMDbk)

## 사용 기술

Frok Game Server Engine을 개발하는데 다음과 같은 기술을 사용했습니다.

- C++ - 개발을 위해 활용환 주 언어입니다.
- ProtoBuf - 서버와 클라이언트의 패킷 직렬화를 쉽게하기 위해서 사용했습니다.
- Python - ProtoBuf의 결과를 자동화하기 위해 사용했습니다.

## 프로젝트 개요
### ServerCore
- 서버와 클라이언트(C++인 경우)가 공유하는 핵심 모듈들을 공유하는 라이브러리 클래스입니다.
- 빌드시 정적 라이브러리 파일(.lib)로 반환됩니다.
- Network 초기화 및 관리
- Thread/Memory 관리
- TLS 및 서버 관리에 필요한 전역 변수
- Json 파싱
- MySQL와 연결
- 비동기 통신 시 패킷을 모아서 보내기 위한 JobQueue 지원

### GameServer
- ServerCore를 이용해서 실제 컨텐츠를 제작하기 위해 만들어진 컨텐츠입니다.
- 빌드 시 ProtoBuf 패킷 클래스가 같이 빌드가 됩니다.
- 각종 패킷들은 PacketManager 클래스를 통해서 가공되어 전달됩니다.
- 클라이언트가 접속하면 세션을 유지해주는 역할을 합니다.
- 세션에 접속된 플레이어들에게 패킷들을 전달하는 역할을 진행합니다.

### DummyClient
- 실제 게임이 아니라 서버에 패킷을 전달하는 것을 테스트 하기 위한 프로젝트입니다.
- 단순히 콘솔창으로 구성되어 있으며, PacketManager를 통해서 프로그래머가 테스트 하고 싶은 패킷을 보낼 수 있습니다.
 
### Tools
- ProtoBuf 패킷을 빌드하는데 필요한 작업을 자동화하는 프로젝트입니다.

### Util
- 개발에 필요한 도움 클래스들을 넣어둔 필터입니다.
- SHA256 코드 출처 : https://github.com/System-Glitch/SHA256