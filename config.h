#define NUMCOLORS       13
#define MODKEY          Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
    
static const unsigned int tagspacing = 0;       /* space between tags */
static const unsigned int tagpadding = 1;      /* inner padding of tags */
static const unsigned int taglinepx = 4;        /* height of tag underline */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const Bool showsystray = True;           /* false means no systray */
static const unsigned int gappx = 10;            /* gaps between windows */
static const unsigned int borderpx = 3;         /* border pixel of windows */
static const unsigned int snap = 32;            /* snap pixel */
static const Bool showbar = True;               /* false means no bar */
static const Bool topbar = True;                /* false means bottom bar */
static const float mfact = 0.50;                /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;                   /* number of clients in master area */
static const Bool resizehints = False;          /* true means respect size hints in tiled resizals */

static const char font[] = "-*-tamsynmod-medium-r-*-*-14-*-*-*-*-*-*-*"; //-*-terminus-medium-r-*-*-20-*-*-*-*-*-*-*";
static const char font2[] = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*"; 
static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg         bg */
    { "#2a2e35", "#f8f8f2", "#2a2e35" },        /* 01 - regular */
    { "#94daa9", "#94daa9", "#2a2e35" },        /* 02 - selected */
    { "#2a2e35", "#FF99CC", "#2a2e35" },        /* 03 - urgent */
    { "#2a2e35", "#666666", "#2a2e35" },        /* 04 - occupied */
    { "#2a2e35", "#f92672", "#2a2e35" },        /* 05 - red */
    { "#2a2e35", "#66d9ef", "#2a2e35" },        /* 06 - blue */
    { "#2a2e35", "#94daa9", "#2a2e35" },        /* 07 - green */
    { "#2a2e35", "#666666", "#2a2e35" },        /* 08 -  */
    { "#2a2e35", "#DCDCDC", "#2a2e35" },        /* 09 -  */
    { "#2a2e35", "#94daa9", "#2a2e35" },        /* 0A - layout colours */
    { "#2a2e35", "#B86A6A", "#2a2e35" },        /* 0B -  dwmstatus blue/grey*/
    { "#2a2e35", "#94daa9", "#5a5a5a" },        /* 0C -  dwmstatus green/grey*/
    { "#2a2e35", "#f8f8f2", "#5a5a5a" },        /* 0D -  dwmstatus normal/grey*/
};

static const Layout layouts[] = {
    /* symbol   gaps    arrange */
    { "þ",      True,   tile },
    { "ü",      True,   bstack },
    { "ÿ",      False,  monocle },
    { "ý",      False,  NULL },
};

static const Tag tags[] = {
    /* name     layout          mfact   nmaster */
    { "web",    &layouts[0],    -1,     -1 },
    { "term",   &layouts[0],    -1,     -1 },
    { "media",  &layouts[1],    .75,     -1 },
    { "misc",   &layouts[0],    -1,     -1 },
    { "mail",   &layouts[0],    -1,     -1 },
};

static const Rule rules[] = {
    /* class                   instance    title       tags mask     isfloating      iscentred       monitor */
   { "Google-chrome-stable",    NULL,       NULL,       1 << 0,       False,            False,       -1 },
   { "Filezilla",               NULL,       NULL,       1 << 3,       False,            False,       -1 },
   { "Pcmanfm",                 NULL,       NULL,       1 << 3,       False,            False,       -1 },
   { "Truecrypt",               NULL,       NULL,       1 << 3,       True,             True,        -1 },
   { "Firefox",                 NULL,       NULL,       1 << 0,       False,            False,       -1 },
   { "Steam",                   NULL,       NULL,       1 << 3,       False,            True,        -1 },
   { "Calibre",                   NULL,       NULL,       1 << 3,       False,            True,        -1 },
   { "Gimp",                    NULL,       NULL,       1 << 3,       True,             True,        -1 },
   { "Nwn",                     NULL,       NULL,       1 << 3,       True,             True,        -1 },
   { "FTL",                     NULL,       NULL,       1 << 3,       True,             True,        -1 },
   {  NULL,                     "mutt",     NULL,       1 << 4,       False,            False,       -1 },
   {  NULL,                     NULL,     "tmux",       1 << 1,       False,            False,       -1 },
   {  NULL,                     NULL,  "youtube",       1 << 2,       False,            False,       -1 },
   { "mpv",                     NULL,       NULL,       1 << 2,       False,            False,       -1 },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *menu[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *webb[] = { "firefox", NULL, "Firefox" };
static const char *file[] = { "pcmanfm", NULL, "Pcmanfm" };
static const char *fz[] = { "filezilla", NULL, "Filezilla" };
static const char *term[] = { "termite", NULL, }; 
static const char   *mailcmd[] = { "termite", "--name=mutt", "-e", "mutt", NULL };

/* Ignore below to use termite instead
static const char   *mailcmd[] = { "urxvtc", "-title", "mutt", "-e", "mutt", NULL };
static const char   *tmuxcmd[] = { "urxvtc", "-title", "tmux", "-e", "tmux", NULL };
static const char   *yt[] = { "urxvtc", "-title", "youtube", "-e", "youtube-viewer", NULL };
static const char *term[] = { "urxvtc", NULL, }; */


static Key keys[] = {
    { MODKEY,           XK_p,       spawn,          {.v = menu } },
    { MODKEY|ShiftMask, XK_w,       runorraise,     {.v = webb } },
    { MODKEY|ShiftMask, XK_Return,  spawn,          {.v = term } },
    { MODKEY|ShiftMask, XK_f,       runorraise,     {.v = file } },
    { MODKEY|ShiftMask, XK_m,       spawn,          {.v = mailcmd } },
    /*
    { MODKEY|ShiftMask, XK_t,       spawn,          {.v = tmuxcmd } },
    { MODKEY|ShiftMask, XK_y,       spawn,          {.v = yt } }, */
    { MODKEY|ShiftMask, XK_z,       runorraise,     {.v = fz } },
    { MODKEY|ShiftMask, XK_q,       quit,           {0} },
    { MODKEY|ShiftMask, XK_b,       togglebar,      {0} },
    { MODKEY|ShiftMask, XK_c,       killclient,     {0} },
    { MODKEY,           XK_Return,  zoom,           {0} },
    { MODKEY,           XK_Tab,     view,           {0} },
    { MODKEY|ControlMask,     XK_f, togglefloating, {0} },
    { MODKEY,           XK_space,   setlayout,      {0} },
    { MODKEY,           XK_t,       setlayout,      {.v = &layouts[0] } },
    { MODKEY,           XK_b,       setlayout,      {.v = &layouts[1] } },
    { MODKEY,           XK_m,       setlayout,      {.v = &layouts[2] } },
    { MODKEY,           XK_f,       setlayout,      {.v = &layouts[3] } },
    { MODKEY,           XK_j,       focusstack,     {.i = +1 } },
    { MODKEY,           XK_k,       focusstack,     {.i = -1 } },
    { MODKEY,           XK_h,       setmfact,       {.f = -0.05 } },
    { MODKEY,           XK_l,       setmfact,       {.f = +0.05 } },
    { MODKEY,           XK_equal,   incnmaster,     {.i = +1 } },
    { MODKEY,           XK_minus,   incnmaster,     {.i = -1 } },
    { MODKEY,           XK_Down,    focusstack,     {.i = +1 } },
    { MODKEY,           XK_Up,      focusstack,     {.i = -1 } },
    { MODKEY,           XK_0,       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0,       tag,            {.ui = ~0 } },
    { MODKEY,           XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,           XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask, XK_period,  tagmon,         {.i = +1 } },
    { MODKEY,                       XK_Left,   cycle,          {.i = -1 } },
    { MODKEY,                       XK_Right,  cycle,          {.i = +1 } },
    { MODKEY|ControlMask,           XK_Left,   tagcycle,       {.i = -1 } },
    { MODKEY|ControlMask,           XK_Right,  tagcycle,       {.i = +1 } },
    { MODKEY|ControlMask,           XK_j,      pushdown,       {0} },                                                                                      
    { MODKEY|ControlMask,           XK_k,      pushup,         {0} },
    { MODKEY|ControlMask,           XK_q,      quit,           {0} },
    TAGKEYS(            XK_1,       0)
    TAGKEYS(            XK_2,       1)
    TAGKEYS(            XK_3,       2)
    TAGKEYS(            XK_4,       3)
    TAGKEYS(            XK_5,       4)
    TAGKEYS(            XK_6,       5)
};

static Button buttons[] = {
    { ClkLtSymbol,      0,          Button1,        setlayout,      {0} },
    { ClkClientWin,     MODKEY,     Button1,        movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button2,        togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3,        resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,        view,           {0} },
    { ClkTagBar,        0,          Button3,        toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1,        tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3,        toggletag,      {0} },
};
