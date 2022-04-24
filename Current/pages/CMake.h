/*!
\page Hc00 CMake

\brief It uses [CMake](https://cmake.org/) for its build system.


\n\n
The build has been tested using `Unix Makefiles` as well as
`Visual Studio 2019` generators.

\n\n
It provides the following definitions.

\n\n
<ul>
<li>Hack_BUILD_TEST    | OFF
<ul>
 <li>Build the unit test program.</li>
</ul>
</li>

<li>Hack_AUTO_RUN_TEST    | OFF
<ul>
 <li>Automatically runs the test program after each build.</li>
</ul>
</li>

<li>Hack_CHECK_INT_BOUNDS    | ON
<ul>
 <li>Throws an overflow exception when testing individual bits.</li>
</ul>
</li>


<li>Hack_IMPLEMENT_BLACK_BOX    | ON
<ul>
 <li>If this is true most chips will be implemented with logic gates.</li>
</ul>
</li>

<li>Hack_PRINT_CHIP_STATE    | OFF
<ul>
 <li>Enables the print method defined in the Chip base class.</li>
</ul>
</li>

<li>Hack_VM_ZERO_RAM    | OFF
<ul>
 <li>Emits extra instructions to zero RAM values that are no longer in use. (Useful when debugging with the Computer option -t) </li>
</ul>
</li>



<li>Hack_BLOCK_PUSH    | OFF
<ul>
 <li>Emits conditional instructions to prevent pushing to segments when its out of context. </li>
</ul>
</li>


<li>Hack_USE_SDL    | OFF
<ul>
 <li>Enables or disables SDL.</li>
</ul>
</li>

 */