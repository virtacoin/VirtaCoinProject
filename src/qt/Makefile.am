include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = virtacoin-qt
noinst_LIBRARIES = libvirtacoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# virtacoin qt core #
QT_TS = \
  locale/virtacoin_ach.ts \
  locale/virtacoin_af_ZA.ts \
  locale/virtacoin_ar.ts \
  locale/virtacoin_be_BY.ts \
  locale/virtacoin_bg.ts \
  locale/virtacoin_bs.ts \
  locale/virtacoin_ca_ES.ts \
  locale/virtacoin_ca.ts \
  locale/virtacoin_ca@valencia.ts \
  locale/virtacoin_cmn.ts \
  locale/virtacoin_cs.ts \
  locale/virtacoin_cy.ts \
  locale/virtacoin_da.ts \
  locale/virtacoin_de_AT.ts \
  locale/virtacoin_de.ts \
  locale/virtacoin_el_GR.ts \
  locale/virtacoin_en.ts \
  locale/virtacoin_eo.ts \
  locale/virtacoin_es_CL.ts \
  locale/virtacoin_es_DO.ts \
  locale/virtacoin_es_MX.ts \
  locale/virtacoin_es.ts \
  locale/virtacoin_es_UY.ts \
  locale/virtacoin_et.ts \
  locale/virtacoin_eu_ES.ts \
  locale/virtacoin_fa_IR.ts \
  locale/virtacoin_fa.ts \
  locale/virtacoin_fi.ts \
  locale/virtacoin_fr_CA.ts \
  locale/virtacoin_fr.ts \
  locale/virtacoin_gl.ts \
  locale/virtacoin_gu_IN.ts \
  locale/virtacoin_he.ts \
  locale/virtacoin_hi_IN.ts \
  locale/virtacoin_hr.ts \
  locale/virtacoin_hu.ts \
  locale/virtacoin_id_ID.ts \
  locale/virtacoin_it.ts \
  locale/virtacoin_ja.ts \
  locale/virtacoin_ka.ts \
  locale/virtacoin_kk_KZ.ts \
  locale/virtacoin_ko_KR.ts \
  locale/virtacoin_ky.ts \
  locale/virtacoin_la.ts \
  locale/virtacoin_lt.ts \
  locale/virtacoin_lv_LV.ts \
  locale/virtacoin_ms_MY.ts \
  locale/virtacoin_nb.ts \
  locale/virtacoin_nl.ts \
  locale/virtacoin_pam.ts \
  locale/virtacoin_pl.ts \
  locale/virtacoin_pt_BR.ts \
  locale/virtacoin_pt_PT.ts \
  locale/virtacoin_ro_RO.ts \
  locale/virtacoin_ru.ts \
  locale/virtacoin_sah.ts \
  locale/virtacoin_sk.ts \
  locale/virtacoin_sl_SI.ts \
  locale/virtacoin_sq.ts \
  locale/virtacoin_sr.ts \
  locale/virtacoin_sv.ts \
  locale/virtacoin_th_TH.ts \
  locale/virtacoin_tr.ts \
  locale/virtacoin_uk.ts \
  locale/virtacoin_ur_PK.ts \
  locale/virtacoin_uz@Cyrl.ts \
  locale/virtacoin_vi.ts \
  locale/virtacoin_vi_VN.ts \
  locale/virtacoin_zh_CN.ts \
  locale/virtacoin_zh_HK.ts \
  locale/virtacoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_virtacoinaddressvalidator.cpp \
  moc_virtacoinamountfield.cpp \
  moc_virtacoingui.cpp \
  moc_virtacoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

VIRTACOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  virtacoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_virtacoin.cpp
QT_QRC = virtacoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

VIRTACOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  virtacoinaddressvalidator.h \
  virtacoinamountfield.h \
  virtacoingui.h \
  virtacoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/virtacoin.ico \
  res/icons/virtacoin.png \
  res/icons/virtacoin_testnet.ico \
  res/icons/virtacoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

VIRTACOIN_QT_CPP = \
  virtacoin.cpp \
  virtacoinaddressvalidator.cpp \
  virtacoinamountfield.cpp \
  virtacoingui.cpp \
  virtacoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  signverifymessagedialog.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp

if ENABLE_WALLET
VIRTACOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

VIRTACOIN_RC = res/virtacoin-qt-res.rc

libvirtacoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libvirtacoinqt_a_SOURCES = $(VIRTACOIN_QT_CPP) $(VIRTACOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libvirtacoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libvirtacoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# virtacoin-qt binary #
virtacoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
virtacoin_qt_SOURCES = virtacoin.cpp
if TARGET_DARWIN
  virtacoin_qt_SOURCES += $(VIRTACOIN_MM)
endif
if TARGET_WINDOWS
  virtacoin_qt_SOURCES += $(VIRTACOIN_RC)
endif
virtacoin_qt_LDADD = libvirtacoinqt.a $(LIBVIRTACOIN_SERVER)
if ENABLE_WALLET
virtacoin_qt_LDADD += $(LIBVIRTACOIN_WALLET)
endif
virtacoin_qt_LDADD += $(LIBVIRTACOIN_CLI) $(LIBVIRTACOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
virtacoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

virtacoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/virtacoinstrings.cpp

translate: virtacoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(VIRTACOIN_QT_CPP) $(VIRTACOIN_QT_H) $(VIRTACOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/virtacoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name virtacoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
