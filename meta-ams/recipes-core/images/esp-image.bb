SUMMARY = "EPS product-grade image"
DESCRIPTION = "Embedded Software Production - HIL Simulator imaage"
LICENSE = "MIT"

require include/ams-image.inc

PR = "1.0.${PR_INC}"

# overwrite image name - to find it in tmp* tree
export IMAGE_BASENAME = "esp-image"

IMAGE_INSTALL_append = " \
  packagegroup-esp \
"
