# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline-Filters
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Common source code filters for Inline Modules

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Inline>=0.42:${PORTSDIR}/devel/p5-Inline \
		p5-Inline-C>=0.42:${PORTSDIR}/devel/p5-Inline-C
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
