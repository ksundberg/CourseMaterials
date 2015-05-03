#ifndef LIONHEART_H
#define LIONHEART_H
#include "unit.h"

#include "m11.h"
#include "adc.h"
#include "adi.h"
#include "adn.h"
#include "akf.h"
#include "all.h"
#include "alt.h"
#include "amo.h"
#include "ark.h"
#include "asd.h"
#include "ben.h"
#include "boo.h"
#include "bos.h"
#include "bot.h"
#include "bri.h"
#include "bro.h"
#include "bug.h"
#include "bwc.h"
#include "cal.h"
#include "car.h"
#include "cdg.h"
#include "cjt.h"
#include "ckc.h"
#include "clg.h"
#include "cls.h"
#include "clu.h"
#include "cmd.h"
#include "cow.h"
#include "cra.h"
#include "crb.h"
#include "crd.h"
#include "csq.h"
#include "ctu.h"
#include "cwc.h"
#include "cze.h"
#include "dfv.h"
#include "die.h"
#include "dih.h"
#include "djh.h"
#include "dkb.h"
#include "dkd.h"
#include "dlr.h"
#include "dlt.h"
#include "dnd.h"
#include "dos.h"
#include "drb.h"
#include "drc.h"
#include "dre.h"
#include "dsc.h"
#include "dss.h"
#include "dww.h"
#include "dxv.h"
#include "edb.h"
#include "eds.h"
#include "emj.h"
#include "fed.h"
#include "god.h"
#include "gst.h"
#include "gwh.h"
#include "hlz.h"
#include "hoe.h"
#include "hsa.h"
#include "hug.h"
#include "ian.h"
#include "icl.h"
#include "ike.h"
#include "ipm.h"
#include "jaz.h"
#include "jbp.h"
#include "jcl.h"
#include "jdd.h"
#include "jds.h"
#include "jen.h"
#include "jfr.h"
#include "jmf.h"
#include "jmh.h"
#include "jms.h"
#include "jmt.h"
#include "jps.h"
#include "jrp.h"
#include "jrw.h"
#include "jta.h"
#include "jtd.h"
#include "jtg.h"
#include "jwl.h"
#include "kac.h"
#include "kdf.h"
#include "kfc.h"
#include "klb.h"
#include "klh.h"
#include "knk.h"
#include "lam.h"
#include "lav.h"
#include "lel.h"
#include "lhm.h"
#include "lia.h"
#include "lmn.h"
#include "loz.h"
#include "maa.h"
#include "mad.h"
#include "med.h"
#include "mjn.h"
#include "mlg.h"
#include "mlm.h"
#include "mlp.h"
#include "mmh.h"
#include "mos.h"
#include "mpf.h"
#include "mrr.h"
#include "msw.h"
#include "mtc.h"
#include "nac.h"
#include "naw.h"
#include "nva.h"
#include "ork.h"
#include "oss.h"
#include "per.h"
#include "pez.h"
#include "phx.h"
#include "pim.h"
#include "pld.h"
#include "pox.h"
#include "psg.h"
#include "pts.h"
#include "rdt.h"
#include "rgw.h"
#include "rha.h"
#include "roa.h"
#include "rob.h"
#include "rtb.h"
#include "sah.h"
#include "sd9.h"
#include "sdw.h"
#include "sgj.h"
#include "slj.h"
#include "sll.h"
#include "sps.h"
#include "tas.h"
#include "tbb.h"
#include "tcg.h"
#include "tdm.h"
#include "tds.h"
#include "tgf.h"
#include "tgy.h"
#include "the.h"
#include "thl.h"
#include "tlp.h"
#include "tom.h"
#include "tpa.h"
#include "trh.h"
#include "tsm.h"
#include "usa.h"
#include "usm.h"
#include "usu.h"
#include "vga.h"
#include "win.h"
#include "wmf.h"
#include "wmj.h"
#include "wnd.h"
#include "wnw.h"
#include "yak.h"
#include "yep.h"
#include "yhg.h"
#include "yip.h"
#include "zio.h"
#include "zmk.h"
#include "zrk.h"
#include "zwh.h"
#include "zzt.h"
#include "zzz.h"

#include "lionheart2.h"

using namespace std;

struct Box{
	int minr;
	int maxr;
	int minc;
	int maxc;
};

bool noPlay[NUMTLAS]={
    1,     0,     0,     0,     0,     0,     1,     0,     0,     0,
    1,     1,     0,     0,     0,     1,     0,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
    0,     0,     1,     0,     0,     0,     1,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    1,     0,     0,     1,     1,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     0,     0,     0,     0,     1,     0,
    1,     0,     0,     0,     0,     0,     1,     1,     0,     1,
    1,     1,     0,     0,     0,     1,     0,     1,     0,     1,
    0,     0,     1,     0,     1,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    0,     0,     0,     0,     0,     1,     0,     1,     0,     0,
    1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     1,     0,     0,     1,     1,     0,     0,     0,     0,
    0,     1,     1,     0,     0,     1,     1,     0,     0,     0
};
static const string tlalist[NUMTLAS]={
"adc", "adi", "adn", "akf", "all", "alt", "amo", "ark", "asd", "ben",
"boo", "bos", "bot", "bri", "bro", "bug", "bwc", "cal", "car", "cdg",
"cjt", "ckc", "clg", "cls", "clu", "cmd", "cow", "cra", "crb", "crd",
"csq", "ctu", "cwc", "cze", "dfv", "die", "dih", "djh", "dkb", "dkd",
"dlr", "dlt", "dnd", "dos", "drb", "drc", "dre", "dsc", "dss", "dww",
"dxv", "edb", "eds", "emj", "fed", "god", "gst", "gwh", "hlz", "hoe",
"hsa", "hug", "ian", "icl", "ike", "ipm", "jaz", "jbp", "jcl", "jdd",
"jds", "jen", "jfr", "jmf", "jmh", "jms", "jmt", "jps", "jrp", "jrw",
"jta", "jtd", "jtg", "jwl", "kac", "kdf", "kfc", "klb", "klh", "knk",
"lam", "lav", "lel", "lhm", "lia", "lmn", "loz", "maa", "mad", "med",
"mjn", "mlg", "mlm", "mlp", "mmh", "mos", "mpf", "mrr", "msw", "mtc",
"nac", "naw", "nva", "ork", "oss", "per", "pez", "phx", "pim", "pld",
"pox", "psg", "pts", "rdt", "rgw", "rha", "roa", "rob", "rtb", "sah",
"sd9", "sdw", "sgj", "slj", "sll", "sps", "tas", "tbb", "tcg", "tdm",
"tds", "tgf", "tgy", "the", "thl", "tlp", "tom", "tpa", "trh", "tsm",
"usa", "usm", "usu", "vga", "win", "wmf", "wmj", "wnd", "wnw", "yak",
"yep", "yhg", "yip", "zio", "zmk", "zrk", "zwh", "zzt", "zzz", "m11"
};
#endif
