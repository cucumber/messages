package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleTableRow message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class PickleTableRow {
    private final List<PickleTableCell> cells;

    public PickleTableRow(
        List<PickleTableCell> cells
    ) {
        this.cells = unmodifiableList(new ArrayList<>(requireNonNull(cells, "PickleTableRow.cells cannot be null")));
    }

    public List<PickleTableCell> getCells() {
        return cells;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PickleTableRow that = (PickleTableRow) o;
        return 
            cells.equals(that.cells);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            cells
        );
    }

    @Override
    public String toString() {
        return "PickleTableRow{" +
            "cells=" + cells +
            '}';
    }
}
