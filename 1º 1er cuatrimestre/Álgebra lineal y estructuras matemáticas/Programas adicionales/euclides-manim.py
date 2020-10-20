# Renderizar con https://github.com/3b1b/manim

from manimlib.imports import *

class Euclides(Scene):
    def construct(self):
        def TransformaArray(mobject1, mobject2, cambios, copia=True):
            for pre_ind,post_ind in cambios:
                if copia:
                    self.play(*[
                        ReplacementTransform(mobject1[i].copy(),mobject2[j])
                        for i,j in zip(pre_ind,post_ind)
                        ],
                        run_time=2
                    )
                else:
                    self.play(*[
                        ReplacementTransform(mobject1[i],mobject2[j])
                        for i,j in zip(pre_ind,post_ind)
                        ],
                        run_time=2
                    )

        # https://github.com/HrushikeshPawar/Mathematics-Videos
        def Table():
            def Letters(obj):
                return TexMobject("\\{}".format(obj)).scale(0.6)

            def VertLines(up, left, down, space, no):
                lines = VGroup()
                for i in range(no):
                    lines.add(Line(up+(left - i*LEFT*2*space),
                    (down - DOWN)+(left - i*LEFT*2*space), stroke_width=0.7))
                return lines

            def HoriLines(up, left, right, space, no):
                lines = VGroup()
                for i in range(no):
                    lines.add(Line(left+(up - i*UP*space),
                    right+(up - i*UP*space), stroke_width=0.7))
                return lines

            letters = VGroup()

            f_1 = TextMobject("-1").move_to(UP*3   + LEFT*6).scale(0.5)
            f0  = TextMobject("0" ).move_to(UP*2.5 + LEFT*6).scale(0.5)
            f1  = TextMobject("1" ).move_to(UP*2   + LEFT*6).scale(0.5)
            f2  = TextMobject("2" ).move_to(UP*1.5 + LEFT*6).scale(0.5)
            f3  = TextMobject("3" ).move_to(UP*1   + LEFT*6).scale(0.5)
            f4  = TextMobject("4" ).move_to(UP*0.5 + LEFT*6).scale(0.5)
            letters.add(f_1, f0, f1, f2, f3, f4)

            r = TextMobject("r").move_to(UP*3.5+LEFT*5)
            c = TextMobject("c").move_to(UP*3.5+LEFT*4)
            u = TextMobject("u").move_to(UP*3.5+LEFT*3)
            v = TextMobject("v").move_to(UP*3.5+LEFT*2)
            letters.add(r, c, u, v)

            global r393, r267, r126, r15, r6, r3

            r393 = TextMobject("393").move_to(UP*3   + LEFT*5.25).scale(0.75)
            r267 = TextMobject("267").move_to(UP*2.5 + LEFT*5.25).scale(0.75)
            r126 = TextMobject("126").move_to(UP*2   + LEFT*5.25).scale(0.75)
            r15  = TextMobject("15" ).move_to(UP*1.5 + LEFT*5.25).scale(0.75)
            r6   = TextMobject("6"  ).move_to(UP*1   + LEFT*5.25).scale(0.75)
            r3   = TextMobject("3"  ).move_to(UP*0.5 + LEFT*5.25).scale(0.75)
            letters.add(r393, r267)

            global c1, c2_1, c8, c2_2

            c1   = TextMobject("1").move_to(UP*2   + LEFT*4.25).scale(0.75)
            c2_1 = TextMobject("2").move_to(UP*1.5 + LEFT*4.25).scale(0.75)
            c8   = TextMobject("8").move_to(UP*1   + LEFT*4.25).scale(0.75)
            c2_2 = TextMobject("2").move_to(UP*0.5 + LEFT*4.25).scale(0.75)

            global u1_1, u0, u1_2, u2, u17, u36

            u1_1 = TextMobject("1"  ).move_to(UP*3   + LEFT*3.25).scale(0.75)
            u0   = TextMobject("0"  ).move_to(UP*2.5 + LEFT*3.25).scale(0.75)
            u1_2 = TextMobject("1"  ).move_to(UP*2   + LEFT*3.25).scale(0.75)
            u2   = TextMobject("-2" ).move_to(UP*1.5 + LEFT*3.25).scale(0.75)
            u17  = TextMobject("17" ).move_to(UP*1   + LEFT*3.25).scale(0.75)
            u36  = TextMobject("-36").move_to(UP*0.5 + LEFT*3.25).scale(0.75)

            global v0, v1_1, v1_2, v3, v25, v53

            v0   = TextMobject("0"  ).move_to(UP*3   + LEFT*2.25).scale(0.75)
            v1_1 = TextMobject("1"  ).move_to(UP*2.5 + LEFT*2.25).scale(0.75)
            v1_2 = TextMobject("-1" ).move_to(UP*2   + LEFT*2.25).scale(0.75)
            v3   = TextMobject("3"  ).move_to(UP*1.5 + LEFT*2.25).scale(0.75)
            v25  = TextMobject("-25").move_to(UP*1   + LEFT*2.25).scale(0.75)
            v53  = TextMobject("53" ).move_to(UP*0.5 + LEFT*2.25).scale(0.75)

            vlines = VertLines(up=UP*3.75, left=LEFT*5.75, down=DOWN*0.75, space=0.5, no=5)
            hlines = HoriLines(up=UP*3.25, left=LEFT*5.75, right=LEFT*1.75, space=0.5, no=7)
            self.play(Write(vlines), Write(hlines), run_time=3)
            self.play(Write(letters, run_time=3))
            self.wait()

        division1 = TexMobject("r_{-1}", "=", "r_0", "\\cdot", "c_1", "+", "r_1").move_to(DOWN*2)
        division2 = TexMobject("r_0",    "=", "r_1", "\\cdot", "c_2", "+", "r_2").move_to(DOWN*2)
        division3 = TexMobject("r_1",    "=", "r_2", "\\cdot", "c_3", "+", "r_3").move_to(DOWN*2)
        division4 = TexMobject("r_2",    "=", "r_3", "\\cdot", "c_4", "+", "r_4").move_to(DOWN*2)

        division1_num = TexMobject("393", "=", "267", "\\cdot", "1", "+", "126").move_to(DOWN*3)
        division2_num = TexMobject("267", "=", "126", "\\cdot", "2", "+", "15").move_to(DOWN*3)
        division3_num = TexMobject("126", "=", "15" , "\\cdot", "8", "+", "6").move_to(DOWN*3)
        division4_num = TexMobject("15",  "=", "6"  , "\\cdot", "2", "+", "3").move_to(DOWN*3)

        trans_division = [
            [(0,1,2,3,4,5,6),
             (0,1,2,3,4,5,6)],
        ]

        Table()
        self.play(Write(division1))
        TransformaArray(division1, division1_num, trans_division)
        self.wait()
        self.play(
            ReplacementTransform(division1_num[4].copy(),c1),
            ReplacementTransform(division1_num[6].copy(),r126),
            FadeOut(division1_num)
        )

        TransformaArray(division1, division2, trans_division, copia=False)
        TransformaArray(division2, division2_num, trans_division)
        self.wait()
        self.play(
            ReplacementTransform(division2_num[4].copy(),c2_1),
            ReplacementTransform(division2_num[6].copy(),r15),
            FadeOut(division2_num)
        )

        TransformaArray(division2, division3, trans_division, copia=False)
        TransformaArray(division3, division3_num, trans_division)
        self.wait()
        self.play(
            ReplacementTransform(division3_num[4].copy(),c8),
            ReplacementTransform(division3_num[6].copy(),r6),
            FadeOut(division3_num)
        )

        TransformaArray(division3, division4, trans_division, copia=False)
        TransformaArray(division4, division4_num, trans_division)
        self.wait()
        self.play(
            ReplacementTransform(division4_num[4].copy(),c2_2),
            ReplacementTransform(division4_num[6].copy(),r3),
            FadeOut(division4_num)
        )
        self.play(FadeOut(division4))

        self.wait(2)

        bezout   = TexMobject("r_i = 393 \\cdot u_i + 267 \\cdot v_i").move_to(DOWN)

        bezout_uv_393 = TexMobject("393", "=", "393", "\\cdot", "1",     "+", "267", "\\cdot", "0"    ).move_to(UP*3  ).scale(0.5)
        bezout_uv_267 = TexMobject("267", "=", "393", "\\cdot", "0",     "+", "267", "\\cdot", "1"    ).move_to(UP*2.5).scale(0.5)
        bezout_uv_126 = TexMobject("126", "=", "393", "\\cdot", "1",     "+", "267", "\\cdot", "(-1)" ).move_to(UP*2  ).scale(0.5)
        bezout_uv_15  = TexMobject("15",  "=", "393", "\\cdot", "(-2)",  "+", "267", "\\cdot", "3"    ).move_to(UP*1.5).scale(0.5)
        bezout_uv_6   = TexMobject("6",   "=", "393", "\\cdot", "17",    "+", "267", "\\cdot", "(-25)").move_to(UP*1  ).scale(0.5)
        bezout_uv_3   = TexMobject("3",   "=", "393", "\\cdot", "(-36)", "+", "267", "\\cdot", "53"   ).move_to(UP*0.5).scale(0.5)

        bezout_u1 = TexMobject("u_1", "=", "u_{-1}", "-", "c_1", "\\cdot", "u_0").move_to(DOWN*2+LEFT*3)
        bezout_u2 = TexMobject("u_2", "=", "u_0",    "-", "c_2", "\\cdot", "u_1").move_to(DOWN*2+LEFT*3)
        bezout_u3 = TexMobject("u_3", "=", "u_1",    "-", "c_3", "\\cdot", "u_2").move_to(DOWN*2+LEFT*3)
        bezout_u4 = TexMobject("u_4", "=", "u_2",    "-", "c_4", "\\cdot", "u_3").move_to(DOWN*2+LEFT*3)

        bezout_u1_num = TexMobject("1",   "=", "1",  "-", "1", "\\cdot", "0"   ).move_to(DOWN*3+LEFT*3)
        bezout_u2_num = TexMobject("-2",  "=", "0",  "-", "2", "\\cdot", "1"   ).move_to(DOWN*3+LEFT*3)
        bezout_u3_num = TexMobject("17",  "=", "1",  "-", "8", "\\cdot", "(-2)").move_to(DOWN*3+LEFT*3)
        bezout_u4_num = TexMobject("-36", "=", "-2", "-", "2", "\\cdot", "17"  ).move_to(DOWN*3+LEFT*3)

        bezout_v1 = TexMobject("v_1", "=", "v_{-1}", "-", "c_1", "\\cdot", "v_0").move_to(DOWN*2+RIGHT*3)
        bezout_v2 = TexMobject("v_2", "=", "v_0",    "-", "c_2", "\\cdot", "v_1").move_to(DOWN*2+RIGHT*3)
        bezout_v3 = TexMobject("v_3", "=", "v_1",    "-", "c_3", "\\cdot", "v_2").move_to(DOWN*2+RIGHT*3)
        bezout_v4 = TexMobject("v_4", "=", "v_2",    "-", "c_4", "\\cdot", "v_3").move_to(DOWN*2+RIGHT*3)

        bezout_v1_num = TexMobject("-1",  "=", "0",  "-", "1", "\\cdot", "1"    ).move_to(DOWN*3+RIGHT*3)
        bezout_v2_num = TexMobject("3",   "=", "1",  "-", "2", "\\cdot", "(-1)" ).move_to(DOWN*3+RIGHT*3)
        bezout_v3_num = TexMobject("-25", "=", "-1", "-", "8", "\\cdot", "3"    ).move_to(DOWN*3+RIGHT*3)
        bezout_v4_num = TexMobject("53",   "=", "3", "-", "2", "\\cdot", "(-25)").move_to(DOWN*3+RIGHT*3)

        trans_bezout = [
            [(0,1,2,3,4,5,6),
             (0,1,2,3,4,5,6)],
        ]

        self.play(Write(bezout))
        self.wait()

        self.play(
            ReplacementTransform(r393.copy(), bezout_uv_393[0]),
            Write(bezout_uv_393[1:9]),
            ReplacementTransform(r267.copy(), bezout_uv_267[0]),
            Write(bezout_uv_267[1:9])
        )
        self.play(
            ReplacementTransform(bezout_uv_393[4].copy(), u1_1),
            ReplacementTransform(bezout_uv_393[8].copy(), v0),
            ReplacementTransform(bezout_uv_267[4].copy(), u0),
            ReplacementTransform(bezout_uv_267[8].copy(), v1_1),
        )
        self.play(
            ReplacementTransform(r126.copy(), bezout_uv_126[0]),
            ReplacementTransform(r15.copy(),  bezout_uv_15[0]),
            ReplacementTransform(r6.copy(),   bezout_uv_6[0]),
            ReplacementTransform(r3.copy(),   bezout_uv_3[0]),

            ReplacementTransform(bezout_uv_267[1:4].copy(), bezout_uv_126[1:4]),
            ReplacementTransform(bezout_uv_267[1:4].copy(), bezout_uv_15[1:4]),
            ReplacementTransform(bezout_uv_267[1:4].copy(), bezout_uv_6[1:4]),
            ReplacementTransform(bezout_uv_267[1:4].copy(), bezout_uv_3[1:4]),

            ReplacementTransform(bezout_uv_267[5:8].copy(), bezout_uv_126[5:8]),
            ReplacementTransform(bezout_uv_267[5:8].copy(), bezout_uv_15[5:8]),
            ReplacementTransform(bezout_uv_267[5:8].copy(), bezout_uv_6[5:8]),
            ReplacementTransform(bezout_uv_267[5:8].copy(), bezout_uv_3[5:8])
        )
        self.wait()

        self.play(
            Write(bezout_u1),
            Write(bezout_v1),
        )
        TransformaArray(bezout_u1, bezout_u1_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_u1_num[0].copy(), bezout_uv_126[4]),
            ReplacementTransform(bezout_u1_num[0].copy(), u1_2)
        )
        TransformaArray(bezout_v1, bezout_v1_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_v1_num[0].copy(), bezout_uv_126[8]),
            ReplacementTransform(bezout_v1_num[0].copy(), v1_2)
        )

        self.play(
            Transform(bezout_u1, bezout_u2),
            Transform(bezout_v1, bezout_v2),
            FadeOut(bezout_u1_num),
            FadeOut(bezout_v1_num),
        )
        TransformaArray(bezout_u2, bezout_u2_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_u2_num[0].copy(), bezout_uv_15[4]),
            ReplacementTransform(bezout_u2_num[0].copy(), u2)
        )
        TransformaArray(bezout_v2, bezout_v2_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_v2_num[0].copy(), bezout_uv_15[8]),
            ReplacementTransform(bezout_v2_num[0].copy(), v3)
        )

        self.play(
            Transform(bezout_u1, bezout_u3),
            Transform(bezout_v1, bezout_v3),
            FadeOut(bezout_u2_num),
            FadeOut(bezout_v2_num),
        )
        TransformaArray(bezout_u3, bezout_u3_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_u3_num[0].copy(), bezout_uv_6[4]),
            ReplacementTransform(bezout_u3_num[0].copy(), u17)
        )
        TransformaArray(bezout_v3, bezout_v3_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_v3_num[0].copy(), bezout_uv_6[8]),
            ReplacementTransform(bezout_v3_num[0].copy(), v25)
        )

        self.play(
            Transform(bezout_u1, bezout_u4),
            Transform(bezout_v1, bezout_v4),
            FadeOut(bezout_u3_num),
            FadeOut(bezout_v3_num),
            FadeOut(bezout_u3_num),
            FadeOut(bezout_v3_num),
        )
        TransformaArray(bezout_u4, bezout_u4_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_u4_num[0].copy(), bezout_uv_3[4]),
            ReplacementTransform(bezout_u4_num[0].copy(), u36)
        )
        TransformaArray(bezout_v4, bezout_v4_num, trans_bezout)
        self.wait()
        self.play(
            ReplacementTransform(bezout_v4_num[0].copy(), bezout_uv_3[8]),
            ReplacementTransform(bezout_v4_num[0].copy(), v53)
        )

        self.wait(10)
