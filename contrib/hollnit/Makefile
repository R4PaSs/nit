NITC=../../bin/nitc
NITLS=../../bin/nitls

all: bin/hollnit

bin/hollnit: $(shell ${NITLS} -M src/hollnit.nit linux) ${NITC} pre-build
	${NITC} src/hollnit.nit -m linux -o $@

bin/texture_atlas_parser: src/texture_atlas_parser.nit
	${NITC} src/texture_atlas_parser.nit -o $@

#src/controls.nit: art/controls.svg
	#make -C ../inkscape_tools/
	#../inkscape_tools/bin/svg_to_png_and_nit art/controls.svg -a assets/ -s src/ -x 2.0 -g

pre-build:
	#src/controls.nit src/spritesheet_city.nit

check: bin/hollnit
	NIT_TESTING=true bin/hollnit

# ---
# Android

android: bin/hollnit.apk
bin/hollnit.apk: $(shell ${NITLS} -M src/hollnit.nit android) ${NITC} res/drawable-hdpi/icon.png pre-build
	${NITC} src/android.nit -m android -o $@

android-release: $(shell ${NITLS} -M src/hollnit.nit android) ${NITC} res/drawable-hdpi/icon.png pre-build
	${NITC} src/android.nit -m android -o bin/hollnit.apk --release

res/drawable-hdpi/icon.png: art/icon.svg
	make -C ../inkscape_tools/
	../inkscape_tools/bin/svg_to_icons --out res --android art/icon.svg
