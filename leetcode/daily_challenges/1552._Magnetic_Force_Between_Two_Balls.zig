const std = @import("std");
const dprint = std.debug.print;
const stdin = std.io.getStdIn().reader();
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

fn get_input() !struct { positions: []usize, balls: usize } {
    var buf: [1024]u8 = undefined;
    var input = (try stdin.readUntilDelimiterOrEof(buf[0..], '\n')).?;

    input = input[1..];
    input = input[0 .. input.len - 1];

    var position = std.ArrayList(usize).init(allocator);

    var iter = std.mem.splitSequence(u8, input, ",");

    while (iter.next()) |pos| {
        try position.append(try std.fmt.parseInt(u8, pos, 10));
    }

    const positions = try position.toOwnedSlice();

    buf = undefined;
    input = (try stdin.readUntilDelimiterOrEof(buf[0..], '\n')).?;
    const balls = try std.fmt.parseInt(u8, input, 10);

    return .{ .positions = positions, .balls = balls };
}

pub fn main() !void {
    const input = try get_input();
    // TODO: Ask "does destructuring syntax works with struct ?"
    const positions = input.positions;
    const balls = input.balls;
    defer allocator.free(input.positions);

    std.mem.sort(usize, positions, {}, comptime std.sort.asc(usize));

    var low: usize = 1;
    var high: usize = positions[positions.len - 1] - positions[0];

    var ans: usize = 1;
    while (low <= high) {
        const mid: usize = low + ((high - low) / 2);
        if (can_place(positions, balls, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    dprint("Ans: {d}\n", .{ans});
}

fn can_place(positions: []const usize, balls: usize, diff: usize) bool {
    var last_placed = positions[0];
    var placed_count: usize = 1;
    var idx: usize = 1;

    // since, constraints says balls >= 2
    // we don't need to check for (placed_count == balls) beforehand
    while (idx < positions.len) : (idx += 1) {
        if (positions[idx] - last_placed >= diff) {
            last_placed = positions[idx];
            placed_count += 1;
        }
        if (placed_count == balls) {
            return true;
        }
    }

    return false;
}
