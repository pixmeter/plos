SUMMARY = "Weather Station from Tinkerforge written in Rust"
HOMEPAGE = "git@gitlab.com:volker-kempert/tinkerforge-weatherstation.git"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=cc38aedb66ffade44ebffd945e837209"

INC_PR = "r0"

inherit cargo

FILES_${PN} += "\
        ${systemd_system_unitdir}/${PN}.service \
        ${sysconfdir}/${PN}.toml \
"

CONFFILES_${PN} += " \
        ${sysconfdir}/${PN}.toml \
"

SYSTEMD_SERVICE_${PN} = "${PN}.service"

do_install_append() {
        install -d ${D}${systemd_unitdir}/system
        install -m 0644 ${THISDIR}/${PN}/${PN}.service ${D}${systemd_system_unitdir}
        install -d ${D}${sysconfdir}
        install -m 0644 ${THISDIR}/${PN}/${PN}.toml ${D}${sysconfdir}
}