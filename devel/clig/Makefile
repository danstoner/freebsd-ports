# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	clig
PORTVERSION=	1.9.11.1
PORTREVISION=	2
CATEGORIES=	devel tcl
MASTER_SITES=	http://wsd.iitb.fhg.de/~geg/clighome/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-generate an (argc, argv) processor, usage message, and manpage

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING-2.0

NO_BUILD=	yes
USES+=		tcl
MAKEFILE=	makefile
MAKE_ENV+=	NOPORTDOCS=${NOPORTDOCS}
MAKE_ARGS=	prefix="${PREFIX}" build_root="${STAGEDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/example/.cvsignore
	@${FIND} -d ${WRKSRC} -type d -and -name CVS -exec ${RM} -r {} \;
	@${REINPLACE_CMD} -e 's|/usr/bin/tclsh|${TCLSH}|; \
		s|/doc/|/share/doc/|; \
		s|-$$(VERSION)||;' \
			${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s|tclsh|${TCLSH}|" \
		${WRKSRC}/man/fixman

.include <bsd.port.mk>
