# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	gbsdconv
PORTVERSION=	11.1
CATEGORIES=	converters python

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=8.0:${PORTSDIR}/converters/py-bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini

USES=		python
USE_GNOME=	gtk30 introspection:run

USE_LDCONFIG=	yes

PLIST_FILES=	bin/gbsdconv \
		lib/gbsdconv_taglib.so \
		%%DATADIR%%/gbsdconv.png \
		%%DATADIR%%/gbsdconv.xml \
		%%DATADIR%%/gbsdconv2.png

.include <bsd.port.mk>
