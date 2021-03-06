# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	cueplayer
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	CUE player

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

USES=		pkgconfig qmake
USE_QT4=	gui xml uic_build moc_build rcc_build network
USE_GSTREAMER=	flac good dvd lame ugly ffmpeg taglib ogg vorbis soup libmms wavpack
USE_XORG=	x11

LICENSE=	GPLv3

DESKTOP_ENTRIES="Cueplayer" "Lightweight media player based on Qt and Gstreamer" \
		"${DATADIR}/${PORTNAME}.png" "${PORTNAME}" \
		"AudioVideo;Audio;Video;" true

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share/cueplayer/,${DATADIR}/,g' \
		${WRKSRC}/main.cpp ${WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX},g' \
		${WRKSRC}/${PORTNAME}.pro
	@${ECHO_CMD} 'PKGCONFIG += x11' >> ${WRKSRC}/${PORTNAME}.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
