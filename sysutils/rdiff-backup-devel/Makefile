# Created by: Vasil Dimov <vd@datamax.bg>
# $FreeBSD$

PORTNAME=	rdiff-backup
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH \
		LOCAL/vd/${PORTNAME}${PKGNAMESUFFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local/remote mirroring+incremental backup

LICENSE=	GPLv2

LIB_DEPENDS=	librsync.so:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-[0-9]*

USES=		python
USE_PYTHON=	distutils

MAN1S=		rdiff-backup.1 rdiff-backup-statistics.1
DOCS=		CHANGELOG README COPYING FAQ.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${MAN1S:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
