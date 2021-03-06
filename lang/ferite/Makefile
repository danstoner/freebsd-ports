# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	ferite
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable scripting language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libxml2.so:${PORTSDIR}/textproc/libxml2

USES=		gmake libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
USE_LDCONFIG=	yes
PLIST_SUB=	MACHINE_ARCH=${MACHINE_ARCH}
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	NOPORTDOCS=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/src/ferite_scanner.c
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} \
		${REINPLACE_CMD} -e "s|-lferite|-lferite -L${WRKSRC}/src/.libs|g"

.include <bsd.port.mk>
