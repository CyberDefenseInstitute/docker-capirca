all: build

build:
	@docker build --tag=cyberdefense.jp/$(shell basename `pwd`) .

release: build
	@docker build --tag=cyberdefense.jp/$(shell basename `pwd`):$(shell cat VERSION) .

push: release
	@docker push cyberdefense.jp/$(shell basename `pwd`):$(shell cat VERSION) 

push-all: push
	@docker push cyberdefense.jp/$(shell basename `pwd`)

dpkg-list:
	@docker run --rm -it cyberdefense.jp/$(shell basename `pwd`) dpkg-query -W > installed-packeges

acl: build
	@docker run -v $(shell pwd)/ACL:/home/user/ACL --rm cyberdefense.jp/$(shell basename `pwd`) aclgen

