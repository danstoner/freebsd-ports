# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	griffith
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/87859599/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.5:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:${PORTSDIR}/graphics/py-pillow \
		${PYXML}

USE_GNOME=	pygtk2
USES=		gmake gettext python tar:xz
NO_BUILD=	yes

OPTIONS_DEFINE=		CHARDET LXML PYGNOMEEXTRAS REPORTLAB2
OPTIONS_DEFAULT=	LXML

CHARDET_DESC=		chardet support
CHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet

LXML_DESC=		lxml support
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml

PYGNOMEEXTRAS_DESC=	python-gnome-extras support
PYGNOMEEXTRAS_USE=	GNOME=pygnomeextras

REPORTLAB2_DESC=	ReportLab2 support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREPORTLAB2}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2:${PORTSDIR}/print/py-reportlab2
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab1>=1.19:${PORTSDIR}/print/py-reportlab1
.endif

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		'/^LANGUAGES=/s|find.*|cd i18n/\&\&ls -d *)|g ; \
		 /^PREFIX/s|?=|=|g ; s|/usr|${PREFIX}|; /ln -s/d; \
		 /^ETCDIR/s|=.*|= $$(PREFIX)/etc|g' ${WRKSRC}/${file}
.endfor
.for f in docs/en/Makefile docs/pl/Makefile docs/pt/Makefile
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|?=|=|g ; s|/usr|${PREFIX}|; \
		 /^MANDIR/s|=.*|=${STAGEDIR}${MANPREFIX}/man|g' \
		 ${WRKSRC}/${f}
.endfor

pre-install:
	${LN} -s ${DATADIR}/lib/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
