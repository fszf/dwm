#define NUMCOLORS       13
#define MODKEY          Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
    
static const unsigned int tagspacing = 1;       /* space between tags */
static const unsigned int tagpadding = 5;      /* inner padding of tags */
static const unsigned int taglinepx = 2;        /* height of tag underline */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const Bool showsystray = True;           /* false means no systray */
static const unsigned int gappx = 8;            /* gaps between windows */
static const unsigned int borderpx = 1;         /* border pixel of windows */
static const unsigned int snap = 32;            /* snap pixel */
static const Bool showbar = True;               /* false means no bar */
static const Bool topbar = True;                /* false means bottom bar */
static const float mfact = 0.50;                /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;                   /* number of clients in master area */
static const Bool resizehints = False;          /* true means respect size hints in tiled resizals */
static const char font[] = "-*-tamsynmod-medium-r-*-*-18-*-*-*-*-*-*-*";

static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg         bg */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 01 - regular */
    { "#4d79ff", "#FFFFFF", "#2D2D2D" },        /* 02 - selected */
    { "#2D2D2D", "#FF0000", "#2D2D2D" },        /* 03 - urgent */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 04 - occupied */
    { "#2D2D2D", "#A82222", "#2D2D2D" },        /* 05 - red */
    { "#2D2D2D", "#4779b3", "#2D2D2D" },        /* 06 - blue */
    { "#2D2D2D", "#349147", "#2D2D2D" },        /* 07 - green */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 08 - dark grey */
    { "#2D2D2D", "#DCDCDC", "#2D2D2D" },        /* 09 - light grey */
    { "#2D2D2D", "#4779b3", "#2D2D2D" },        /* 0A - orange */
    { "#2D2D2D", "#B86A6A", "#2D2D2D" },        /* 0B - pink */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 0C - white */
    { "#2D2D2D", "#000000", "#2D2D2D" },        /* 0D - black */
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
    { "media",  &layouts[3],    -1,     -1 },
    { "steam",  &layouts[0],    -1,     -1 },
    { "mail",   &layouts[0],    -1,     -1 },
    { "misc",   &layouts[0],    -1,     -1 },
};

static const Rule rules[] = {
    /* class        instance    title       tags mask     isfloating      iscentred       monitor */
   { "Chromium",    NULL,       NULL,       1 << 0,       False, True,       -1 },
   { "Filezilla",   NULL,       NULL,       1 << 0,       True,  True,       -1 },
   { "Spacefm",     NULL,       NULL,       0,            True,  True,       -1 },
   { "Truecrypt",   NULL,       NULL,       0,            True,  True,       -1 },
   { "Dwb",         NULL,       NULL,       1 << 0,       False, False,      -1 },
   { "Steam",       NULL,       NULL,       1 << 3,       False, True,       -1 },
   { "Gimp",        NULL,       NULL,       0,            True,  True,       -1 },
   {  NULL,         "mutt",     NULL,       1 << 4,       False, False,       -1 },
   {  NULL,         "tmux",     NULL,       1 << 1,       False, False,       -1 },
   {  NULL,         "YouTube",  NULL,       1 << 2,       True, True,       -1 },
   { "mpv",         NULL,       NULL,       0,            True,  True,       -1 },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *menu[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *webb[] = { "dwb", NULL, "Dwb" };
static const char *file[] = { "pcmanfm", NULL, "Pcmanfm" };
static const char *term[] = { "termite", NULL,  };
static const char   *mailcmd[] = { "termite", "--name=mutt", "-e", "mutt", NULL };
static const char   *tmuxcmd[] = { "termite", "--name=tmux", "-e", "tmux", NULL };
static const char   *yt[] = { "termite", "--name=YouTube", "-e", "youtube-viewer", NULL };
static const char *fz[] = { "filezilla", NULL,  };


static Key keys[] = {
    { MODKEY,           XK_p,       spawn,          {.v = menu } },
    { MODKEY|ShiftMask, XK_w,       runorraise,          {.v = webb } },
    { MODKEY|ShiftMask, XK_Return,  spawn,     {.v = term } },
    { MODKEY|ShiftMask, XK_f,       runorraise,     {.v = file } },
    { MODKEY|ShiftMask, XK_t,       runorraise,     {.v = tmuxcmd } },
    { MODKEY|ShiftMask, XK_m,       runorraise,     {.v = mailcmd } },
    { MODKEY|ShiftMask, XK_y,       runorraise,     {.v = yt } },
    { MODKEY|ShiftMask, XK_z,       runorraise,     {.v = fz } },
    { MODKEY|ShiftMask, XK_q,       quit,           {0} },
    { MODKEY|ShiftMask, XK_b,       togglebar,      {0} },
    { MODKEY|ShiftMask, XK_c,       killclient,     {0} },
    { MODKEY,           XK_Return,  zoom,           {0} },
    { MODKEY,           XK_Tab,     view,           {0} },
    { MODKEY|ControlMask,           XK_f, togglefloating, {0} },
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
