DEPENDS += "openssl "

export OPENSSL_DIR = "${STAGING_EXECPREFIXDIR}"
export LIBIOTHSM_NOBUILD="On"
cargo_common_do_configure:append () {
	cat <<- EOF >> ${CARGO_HOME}/config

	[net]
	git-fetch-with-cli = true
	EOF
}

do_compile:prepend () {
    export CARGO_HTTP_MULTIPLEXING=false
}

do_install () {
    # Binaries
    install -d  "${D}${bindir}"
    install -m 755 "${WORKDIR}/build/target/${TARGET_SYS}/release/iotedge" ${D}${bindir}/iotedge
}
